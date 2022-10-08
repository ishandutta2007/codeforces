#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

Int n;
Int nums[100001];

Int gcd(Int a,Int b)
{
    Int r;

    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }

    return a;
}

int main()
{
    Int i;
    Int ALLSUM=0,EDIF=0;
    Int cursum=0;
    Int top,bot,nod;

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&nums[i]);
        ALLSUM+=nums[i];
    }

    sort(nums+1,nums+1+n);

    cursum=nums[1];

    for (i=2;i<=n;i++)
    {
        EDIF=EDIF+( (i-1)*nums[i]-cursum );

        cursum+=nums[i];
    }

    top=2*EDIF+ALLSUM;
    bot=n;

    nod=gcd(top,bot);

    top/=nod;
    bot/=nod;

    printf("%I64d %I64d\n",top,bot);

    return 0;
}