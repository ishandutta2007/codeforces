#include <iostream>
#include <stdio.h>
using namespace std;

int maxdays=0;
int mindays=0;
int curday;
int n;

int main()
{
    int i;

    scanf("%d",&n);

    curday=6;

    for (i=1;i<=n;i++)
    {
        if (curday==6 || curday==7)
        maxdays++;

        curday++;
        if (curday==8)
        curday=1;
    }

    curday=1;
    for (i=1;i<=n;i++)
    {
        if (curday==6 || curday==7)
        mindays++;

        curday++;
        if (curday==8)
        curday=1;
    }

    printf("%d %d\n",mindays,maxdays);

    return 0;
}