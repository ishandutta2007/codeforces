#include <iostream>
#include <stdio.h>
using namespace std;

int HPy,ATKy,DEFy;
int HPm,ATKm,DEFm;
int h,a,d;

int MAX(int a,int b)
{
    if (a>b)
    return a;
    else
    return b;
}

int GetHP(int atk,int def)
{
    if (DEFm>=(ATKy+atk))
    return -1;

    int HP1=HPy,HP2=HPm;

    while(HP2>0)
    {
        HP1-=MAX(0,ATKm-(DEFy+def));
        HP2-=MAX(0,(ATKy+atk)-DEFm);
    }

    if (HP1>0)
    return 0;
    else
    return (-HP1)+1;
}

int main()
{
    int i,j;
    int hpneed;
    int cur,themin=-1;

    scanf("%d %d %d",&HPy,&ATKy,&DEFy);
    scanf("%d %d %d",&HPm,&ATKm,&DEFm);
    scanf("%d %d %d",&h,&a,&d);

    for (i=0;i<=210;i++)
    {
        for (j=0;j<=210;j++)
        {
            hpneed=GetHP(i,j);

            if (hpneed==-1)
            continue;

            cur=hpneed*h+i*a+j*d;

            if (cur<themin || themin==-1)
            themin=cur;
        }
    }

    printf("%d\n",themin);

    return 0;
}