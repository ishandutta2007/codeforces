#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

struct add
{
    Int howmuch,towho;
};

Int nums[100001];

int main()
{
    Int n;
    Int i;
    Int thelen,thenum;
    Int ctr=0;
    Int curadd;
    Int total;

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&nums[i]);
    }

    thenum=nums[1];
    thelen=1;

    ctr=nums[1];

    for (i=2;i<=n;i++)
    {
        if (nums[i]==nums[i-1])
        {
            thelen++;
        }
        else
        {
            curadd=thenum;
            total=thelen;
            while(curadd<nums[i] && total>0)
            {
                if (total%2==0)
                {
                    ctr++;
                }
                total=total/2;
                curadd++;
            }

            if (curadd==nums[i])
            {
                thelen=1+total;
                thenum=nums[i];
            }
            else
            {
                ctr=ctr+(nums[i]-curadd);
                thelen=1;
                thenum=nums[i];
            }
        }
    }

    while(thelen>0)
    {
        if (thelen%2==0)
        {
            ctr++;
        }
        thelen=thelen/2;
    }

    printf("%I64d\n",ctr);

    return 0;
}