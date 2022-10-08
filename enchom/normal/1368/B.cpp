#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long llong;

llong ctrs[21];
llong k;

llong prod()
{
    int i;
    llong ans = 1LL;

    for (i=1;i<=10;i++)
    {
        ans *= ctrs[i];
    }

    return ans;
}

const string CF = "codeforces";

int main()
{
    int i,j;

    scanf("%lld",&k);

    for (i=1;i<=10;i++)
    {
        ctrs[i] = 1LL;
    }

    while(prod() < k)
    {
        for (i=1;i<=10;i++)
        {
            ctrs[i]++;

            if (prod() >= k)
                break;
        }
    }

    for (i=1;i<=10;i++)
    {
        for (j=1;j<=ctrs[i];j++)
        {
            printf("%c", CF[i-1]);
        }
    }
    printf("\n");

    return 0;
}