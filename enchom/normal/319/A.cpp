#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

char a[101];
const Int MOD=1000000007;

Int Fast2Pow(Int k)
{
    if (k==0)
    {
        return 1;
    }
    Int POWER=Fast2Pow(k/2);

    if (k%2==0)
    return (POWER*POWER)%MOD;
    else
    return (POWER*POWER*2)%MOD;
}

int main()
{
    Int n;
    Int i;
    Int total=0;
    Int current;

    scanf("%s",a);
    n=strlen(a);

    for (i=0;i<n;i++)
    {
        if (a[i]=='1')
        {
            current=(Fast2Pow(i)*Fast2Pow(2*n-2*i-2))%MOD;
            total+=current;
            if (total>=MOD)
            total-=MOD;
        }
    }

    printf("%I64d\n",total);

    return 0;
}