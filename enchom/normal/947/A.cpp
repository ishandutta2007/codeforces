#include <iostream>
#include <stdio.h>
using namespace std;

int largestPrime[1000111];
bool Prime[1000111];

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

int getMinPrev(int x)
{
    return MAX(3,x-largestPrime[x]+1);
}

int main()
{
    int i,j;
    int minVal=1000000000;

    for (i=2;i<=1000000;i++)
    {
        Prime[i]=true;
    }

    for (i=1;i<=1000000;i++)
    {
        if (Prime[i])
        {
            for (j=i+i;j<=1000000;j+=i)
            {
                Prime[j]=false;
                largestPrime[j]=i;
            }
        }
    }

    int x;

    scanf("%d",&x);

    for (i=x;i>=x-largestPrime[x]+1 && i>=3;i--)
    {
        minVal=MIN(minVal,getMinPrev(i));
    }

    printf("%d\n",minVal);

    return 0;
}