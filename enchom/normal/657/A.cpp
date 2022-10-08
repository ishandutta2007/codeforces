#include <iostream>
#include <stdio.h>
using namespace std;

int n,h,d;

int main()
{
    int i;
    int prev;
    int ctr=0;

    scanf("%d %d %d",&n,&d,&h);

    if (d==1)
    {
        if (n==2)
        {
            printf("1 2\n");
        }
        else
        {
            printf("-1\n");
        }

        return 0;
    }

    if (d>2*h)
    {
        printf("-1\n");
        return 0;
    }

    if (h>d)
    {
        printf("-1\n");
        return 0;
    }

    if (h==1)
    {
        for (i=2;i<=n;i++)
        {
            printf("1 %d\n",i);
        }

        return 0;
    }

    for (i=2;i<=h+1;i++)
    {
        printf("%d %d\n",i-1,i);
    }
    prev=1;
    for (i=h+2;i<=h+2+(d-h)-1;i++)
    {
        printf("%d %d\n",prev,i);
        prev=i;
    }
    ctr=h+2+(d-h)-1;

    for (i=ctr+1;i<=n;i++)
    {
        printf("2 %d\n",i);
    }

    return 0;
}