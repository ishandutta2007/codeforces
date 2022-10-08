#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

Int k;
char inp[100001];
Int L;
const Int MOD=1000000007;
Int magicsum=0;

Int FastPow(Int k,Int p)
{
    if (p==0)
    return 1;

    Int POWER=FastPow(k,p/2);

    if (p%2==1)
    {
        return (((POWER*POWER)%MOD)*k)%MOD;
    }
    else
    {
        return (POWER*POWER)%MOD;
    }
}

Int MultiplicativeInverse(Int top,Int bot)
{
    Int ans=top*FastPow(bot,MOD-2);

    ans%=MOD;

    return ans;
}

int main()
{
    Int i;
    Int magicnum;
    Int z,x;

    scanf("%s",inp);
    scanf("%I64d",&k);

    L=strlen(inp);

    for (i=0;i<L;i++)
    {
        if (inp[i]=='0' || inp[i]=='5')
        {
            magicsum+=FastPow(2,i);
        }
    }

    magicsum=magicsum%MOD;

    z=FastPow( 2,k*L )-1;
    if (z<0)
    z+=MOD;

    x=FastPow(2,L)-1;
    if (x<0)
    x+=MOD;

    magicnum=MultiplicativeInverse(z,x);

    magicsum*=magicnum;
    magicsum%=MOD;

    printf("%I64d\n",magicsum);

    return 0;
}