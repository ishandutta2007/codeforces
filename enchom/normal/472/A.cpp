#include <iostream>
#include <stdio.h>
using namespace std;

bool Prime[1000001];

int main()
{
    int i,j;
    int n;

    for (i=1;i<=1000000;i++)
    {
        Prime[i]=true;
    }
    Prime[1]=false;

    for (i=1;i<=1000000;i++)
    {
        if (Prime[i])
        {
            for (j=i+i;j<=1000000;j+=i)
            {
                Prime[j]=false;
            }
        }
    }

    scanf("%d",&n);

    for (i=2;i<=n-1;i++)
    {
        if (!Prime[i] && !Prime[n-i])
        {
            printf("%d %d\n",i,n-i);
            return 0;
        }
    }

    return 0;
}