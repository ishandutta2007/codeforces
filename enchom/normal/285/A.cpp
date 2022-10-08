#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int perm[100001];

int main()
{
    Int d;
    Int n,k;
    Int i;

    scanf("%I64d %I64d",&n,&k);

    for (i=1;i<=n;i++)
    {
        perm[i]=i;
    }
    for (i=k+1;i>=1;i--)
    {
        printf("%I64d",perm[i]);

        if (k+1!=n)
        {
            printf(" ");
        }
        else
        {
            if (i!=1)
            {
                printf(" ");
            }
        }
    }

    for (i=k+2;i<=n;i++)
    {
        printf("%I64d",perm[i]);

        if (i!=n)
        printf(" ");
    }
    printf("\n");
    return 0;
}