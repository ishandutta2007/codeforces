#include <iostream>
#include <stdio.h>
using namespace std;

int n,m;
int a[3002];
int b[3002];

int main()
{
    int i;
    int uk1,uk2;
    int ctr=0;

    scanf("%d %d",&n,&m);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }

    for (i=1;i<=m;i++)
    {
        scanf("%d",&b[i]);
    }

    uk1=n;
    uk2=m;

    while(uk1>0 && uk2>0)
    {
        if (b[uk2]>=a[uk1])
        {
            uk2--;
            uk1--;
        }
        else
        {
            uk1--;
            ctr++;
        }
    }

    if (uk2==0)
    {
        ctr+=uk1;
    }

    printf("%d\n",ctr);

    return 0;
}