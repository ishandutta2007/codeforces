#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef int Int;

Int dif[1000001];
Int nums[5001];
Int L;
Int UTFO[1000001];
Int Key=1;

Int counter=0;

Int ABS(Int a)
{
    if (a<0)
    {
        return a*-1;
    }
    else
    {
        return a;
    }
}

int main()
{
    Int n,k;
    Int i,j,in;
    Int total=0;
    Int copyofk;
    Int rem;

    for (i=0;i<=1000000;i++)
    {
        UTFO[i]=0;
    }

    scanf("%d %d",&n,&k);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&nums[i]);
    }

    for (i=1;i<=n;i++)
    {
        for (j=1;j<i;j++)
        {
            dif[ ABS(nums[i]-nums[j]) ]++;
        }
    }

    for (i=1;i<=1000001;i++)
    {
        L=0;
        total=0;
        copyofk=k;

        for (j=i;j<=1000000;j+=i)
        {
            total+=dif[j];
            if (total>( k*(k+1) )/2 )
            {
                break;
            }
        }
        if (total<=k)
        {
            printf("%d\n",i);
            break;
        }
        if (total>( k*(k+1) )/2 )
        {
            continue;
        }

        Key++;

        for (j=1;j<=n;j++)
        {
            rem=nums[j]%i;

            if (UTFO[rem]!=Key)
            {
                UTFO[rem]=Key;
            }
            else
            {
                copyofk--;
            }
        }

        if (copyofk>=0)
        {
            printf("%d\n",i);
            break;
        }
    }

    return 0;
}