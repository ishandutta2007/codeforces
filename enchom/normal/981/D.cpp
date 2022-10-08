#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long llong;

int n,k;
llong nums[101];

bool F[52][52];
bool goodSum[52][52];

bool canDo(llong mask)
{
    int i,j,in;
    llong sum = 0;

    memset(F,false,sizeof(F));
    memset(goodSum,false,sizeof(goodSum));

    for (i=1;i<=n;i++)
    {
        sum = 0;

        for (j=i;j<=n;j++)
        {
            sum += nums[j];

            if ( (sum&mask) == mask )
            {
                goodSum[i][j] = true;
            }
        }
    }

    F[0][0] = true;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=k;j++)
        {
            for (in=i-1;in>=0;in--)
            {
                if (goodSum[in+1][i] && F[in][j-1])
                {
                    F[i][j] = true;
                    break;
                }
            }
        }
    }

    return F[n][k];
}

int main()
{
    int i,j;
    llong mask = 0;
    llong testMask;

    scanf("%d %d",&n,&k);

    for (i=1;i<=n;i++)
    {
        scanf("%lld",&nums[i]);
    }

    for (i=60;i>=0;i--)
    {
        testMask = mask;
        testMask |= (1LL << i);

        if (canDo(testMask))
        {
            mask = testMask;
        }
    }

    printf("%lld\n",mask);

    return 0;
}