#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int main()
{
    Int n;
    Int i;

    scanf("%I64d",&n);

    if (n%2==0)
    {
        printf("-1\n");
        return 0;
    }

    for (i=0;i<n;i++)
    {
        printf("%I64d",i);
        if (i!=n)
        printf(" ");
    }
    printf("\n");

    for (i=0;i<n;i++)
    {
        printf("%I64d",i);
        if (i!=n)
        printf(" ");
    }
    printf("\n");

    for (i=0;i<n;i++)
    {
        printf("%I64d", (2*i)%n );
        if (i!=n)
        printf(" ");
    }
    printf("\n");

    return 0;
}