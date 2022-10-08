#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

Int largest;
Int n;
Int nums[101];

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
    Int dif;
    bool OK=false;
    Int nod;
    Int amount;

    scanf("%I64d",&n);

    largest=0;

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&nums[i]);

        if (nums[i]>largest)
        largest=nums[i];
    }

    nod=gcd(nums[1],nums[2]);

    for (i=3;i<=n;i++)
    {
        nod=gcd(nod,nums[i]);
    }

    amount=largest/nod;

    if ( (amount-n)%2==0 )
    {
        printf("Bob\n");
    }
    else
    {
        printf("Alice\n");
    }


    return 0;
}