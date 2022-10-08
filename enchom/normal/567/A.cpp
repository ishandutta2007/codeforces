#include <iostream>
#include <stdio.h>
using namespace std;
#define INF 2000000001

int MIN(int a,int b)
{
    if (a<b)
    return a;
    else
    return b;
}

int MAX(int a,int b)
{
    if (a>b)
    return a;
    else
    return b;
}

int n;
int x[100111];

int main()
{
    int i;
    int v1,v2;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&x[i]);
    }

    for (i=1;i<=n;i++)
    {
        v1=INF;
        v2=INF;

        if (i!=1)
        v1=x[i]-x[i-1];
        if (i!=n)
        v2=x[i+1]-x[i];

        printf("%d ",MIN(v1,v2));

        v1=x[i]-x[1];
        v2=x[n]-x[i];

        printf("%d\n",MAX(v1,v2));
    }

    return 0;
}