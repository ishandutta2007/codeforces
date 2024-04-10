#include <iostream>
#include <stdio.h>
#include <set>
#include <algorithm>
using namespace std;
typedef long long llong;

int t;
int n;
llong F[511];
llong Fsum[511];

pair<llong, int> nums[511];

void reorder()
{
    sort(nums+1,nums+1+n);
    reverse(nums+1,nums+1+n);

    while(n > 0 && nums[n].first == 0)
        n--;

    if (n > 0)
        reverse(nums+1,nums+1+n);
}

int main()
{
    int a, b, c;
    int i;
    int test;

    F[1] = 1;
    F[2] = 1;
    Fsum[1] = 1;
    Fsum[2] = 2;

    for (i=3;i<=50;i++)
    {
        F[i] = F[i-1] + F[i-2];
        Fsum[i] = Fsum[i-1] + F[i];
    }

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%d", &n);

        llong numSum = 0;
        for (i=1;i<=n;i++)
        {
            scanf("%lld", &nums[i].first);
            nums[i].second = i;
            numSum += nums[i].first;
        }

        reorder();

        int sumInd = -1;
        for (i=1;i<=50;i++)
        {
            if (numSum == Fsum[i])
            {
                sumInd = i;
                break;
            }
        }

        if (sumInd == -1)
        {
            printf("NO\n");
            continue;
        }

        bool success = true;
        int lastWinner = -1;
        for (i=sumInd;i>=1;i--)
        {
            if (nums[n].first < F[i])
            {
                success = false;
                break;
            }

            if (lastWinner == nums[n].second)
            {
                if (n > 1 && nums[n-1].first == nums[n].first)
                {
                    swap(nums[n-1], nums[n]);
                }
                else
                {
                    success = false;
                    break;
                }
            }

            nums[n].first -= F[i];
            lastWinner = nums[n].second;

            reorder();
        }

        if (!success)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}