#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long llong;

int M = 10000000, GOAL;
int ctr[20000111];
int sums[20000111];
int n;

int nums[400111];

llong getInRange(int L, int R)
{
    int i;
    llong ans = 0;

    for (i=0;i<=M;i++)
    {
        int l = max(i + 1, L - i);
        int r = min(M, R - i);

        if (l <= r)
            ans += (llong)(sums[r] - sums[l-1]) * (llong)ctr[i];
    }

    for (i=0;i<=M;i++)
    {
        if (2*i >= L && 2*i <= R)
        {
            ans += (llong)ctr[i] * (llong)(ctr[i]-1) / 2LL;
        }
    }

    return ans;
}

int main()
{
    int i,j;
    int answer = 0;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&nums[i]);
    }

    for (i=24;i>=0;i--)
    {
        //cout<<endl;
        //cout<<(1<<i)<<endl;

        llong ans = 0;
        GOAL = (1<<(i+1));
        M = min(10000000, GOAL-1);
        for (j=1;j<=n;j++)
        {
            if (nums[j] >= GOAL)
                nums[j] -= GOAL;

            ctr[ nums[j] ]++;

            //cout<<nums[j]<<" ";
        }
        //cout<<endl;

        sums[0] = ctr[0];
        for (j=1;j<=M;j++)
        {
            sums[j] = sums[j-1] + ctr[j];
        }

        ans += getInRange(GOAL/2, GOAL-1);
        ans += getInRange(GOAL + GOAL/2, 2*GOAL-1);

        for (j=1;j<=n;j++)
        {
            ctr[ nums[j] ]--;
        }

        if (ans % 2 == 1)
        {
            //cout<<"TRUE FOR "<<(1<<i)<<endl;
            answer = answer | (1<<i);
        }
    }

    printf("%d\n",answer);

    return 0;
}