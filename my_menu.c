/**************************************************************************************************/
/* Copyright (C) sa614163@mail.ustc.edu.cn, 2014-2015                                             */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  Willszp                                                              */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/16                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Willszp, 2014/09/16
 *
 */


#include <stdio.h>
#include <stdlib.h>

int Help();

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10

/* data struct */

typedef struct DataNode
{
    char*   cmd;
    char*   desc;
    int     (*handler)();
    struct DataNode *next;
} tDataNode;

/* init the cmd menu */ 
static tDataNode head[]=
{
    {"help","this is help cmd!",Help,&head[1]},
    {"version","cmd program v1.1",NULL,NULL}
};


main()
{
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd > ");
        scanf("%s", cmd);
        tDataNode *p = head;
        while(p != NULL)
        {    
            if( p != NULL)
            {
                printf("%s - %s\n", p->cmd, p->desc); 
                if(p->handler != NULL) 
                { 
                    p->handler();
                }
                break;
            }
            p = p->next;
        }
        if(p == NULL)
        {
            printf("This is a wrong cmd!\n");
        }
    }
}

/* display all cmd */
int Help()
{
    printf("Menu List:\n");
    tDataNode *p = head;
    while(p !=NULL)
    {
        printf("%s - %s\n",p->cmd,p->desc);
        p = p->next;
    }
    return 0; 
}
