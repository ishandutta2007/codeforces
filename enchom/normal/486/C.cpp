#include <iostream>
#include <stdio.h>
using namespace std;

int n,p;
char str[100001];

bool OK(int k)
{
    if (str[k]!=str[n-k+1])
    return false;
    else
    return true;
}

int Dist(int k)
{
    int a=str[k]-'a';
    int b=str[n-k+1]-'a';
    int swp;
    int v1,v2;

    if (a>b)
    {
        swp=a;
        a=b;
        b=swp;
    }

    v1=b-a;
    v2=(a+26)-b;

    if (v1<v2)
    return v1;
    else
    return v2;
}

int main()
{
    int i;
    int leftrun,rightrun;
    int run=0;
    int ans=0;

    scanf("%d %d",&n,&p);
    scanf("%s",str+1);

    if (p<=n/2)
    {
        leftrun=0;
        for (i=p;i>=1;i--)
        {
            if (!OK(i))
            {
                leftrun=p-i;
            }
        }

        rightrun=0;
        for (i=p;i<=n/2;i++)
        {
            if (!OK(i))
            {
                rightrun=i-p;
            }
        }

        if (leftrun<=rightrun)
        {
            run=leftrun*2+rightrun;
        }
        else
        {
            run=leftrun+rightrun*2;
        }
    }
    else
    {
        leftrun=0;
        for (i=p;i>n/2;i--)
        {
            if (!OK(i))
            {
                leftrun=p-i;
            }
        }

        rightrun=0;
        for (i=p;i<=n;i++)
        {
            if (!OK(i))
            {
                rightrun=i-p;
            }
        }

        if (leftrun<=rightrun)
        {
            run=2*leftrun+rightrun;
        }
        else
        {
            run=leftrun+2*rightrun;
        }
    }

    for (i=1;i<=n/2;i++)
    {
        if (!OK(i))
        {
            ans+=Dist(i);
        }
    }

    printf("%d\n",run+ans);

    return 0;
}