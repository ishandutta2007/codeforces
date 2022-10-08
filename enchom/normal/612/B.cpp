#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int n;
int p[300111];
int where[300111];

int ABS(int a)
{
    if (a<0)
    return -a;
    else
    return a;
}

int main()
{
    Int sum=0;
    int i;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);

        where[ p[i] ]=i;
    }

    for (i=1;i<n;i++)
    {
        sum+=(Int)ABS(where[i]-where[i+1]);
    }

    printf("%lld\n",sum);

    return 0;
}