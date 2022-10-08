#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int main()
{
    Int i;
    Int n;
    Int counter=0;
    Int k;
    Int lost=0;

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&k);

        if (k==0)
        {
            lost+=counter;
        }
        else
        {
            counter++;
        }
    }

    printf("%I64d\n",lost);

    return 0;
}