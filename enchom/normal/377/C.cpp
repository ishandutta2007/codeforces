#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct command
{
    bool pick;
    int tm;
};

int a[101];
int n,m;
command commands[21];
int F[21][1048576];
bool taken[21];

void Calc(int cm,int mask)
{
    if (F[cm][mask]!=-1)
    return;

    int i;

    if (cm+1>m)
    {
        F[cm][mask]=0;

        return;
    }

    if (commands[cm+1].pick)
    {
        for (i=1;i<=n;i++)
        {
            if (!taken[i])
            {
                taken[i]=true;

                Calc( cm+1,mask+(1<<(i-1)) );

                taken[i]=false;

                F[cm][mask]=F[cm+1][ mask+(1<<(i-1)) ];

                if (commands[cm+1].tm==1)
                {
                    F[cm][mask]+=a[i];
                }
                else
                {
                    F[cm][mask]-=a[i];
                }

                break;
            }
        }
    }
    else
    {
        Calc(cm+1,mask);

        F[cm][mask]=F[cm+1][mask];

        for (i=1;i<=n;i++)
        {
            if (!taken[i])
            {
                taken[i]=true;

                Calc( cm+1,mask+(1<<(i-1)) );

                taken[i]=false;

                if (commands[cm+1].tm==1)
                {
                    if (F[cm+1][ mask+(1<<(i-1)) ]>F[cm][mask])
                    {
                        F[cm][mask]=F[cm+1][ mask+(1<<(i-1)) ];
                    }
                }
                else
                {
                    if (F[cm+1][ mask+(1<<(i-1)) ]<F[cm][mask])
                    {
                        F[cm][mask]=F[cm+1][ mask+(1<<(i-1)) ];
                    }
                }
            }
        }
    }

    return;
}

int main()
{
    int i;
    char ch;
    int team;
    int firstteam;

    memset(taken,false,sizeof(taken));
    memset(F,-1,sizeof(F));

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }

    scanf("%d",&m);

    sort(a+1,a+1+n);
    reverse(a+1,a+1+n);

    n=m;

    for (i=1;i<=m;i++)
    {
        ch='.';

        while(ch!='p' && ch!='b')
        {
            scanf("%c",&ch);
        }

        scanf("%d",&commands[i].tm);

        if (ch=='p')
        {
            commands[i].pick=true;
        }
        else
        {
            commands[i].pick=false;
        }
    }

    Calc(0,0);

    printf("%d\n",F[0][0]);

    return 0;
}
/**
6
6 4 5 4 5 5
4
b 2
p 1
b 1
p 2
**/