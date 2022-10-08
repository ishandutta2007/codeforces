#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int t;
int n;
int nums[200111];
vector< pair<int, int> > blocks;
vector<int> ans;

int main()
{
    int test;
    int n;
    int i, j;


    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%d", &n);

        for (i=1;i<=n;i++)
        {
            scanf("%d", &nums[i]);
        }

        sort(nums + 1, nums + 1 + n);

        if (n % 2 == 1)
        {
            printf("NO\n");
            continue;
        }

        ans.clear();

        for (i=1;i<=n/2;i++)
        {
            ans.push_back(nums[i]);
            ans.push_back(nums[i + n / 2]);
        }

        bool good = ans[0] != ans.back();
        for (i=1;i<ans.size();i++)
        {
            if (ans[i] == ans[i-1])
                good = false;
        }

        if (!good)
            printf("NO\n");
        else
        {
            printf("YES\n");
            for (i=0;i<ans.size();i++)
            {
                if (i != 0)
                    printf(" ");
                printf("%d", ans[i]);
            }
            printf("\n");
        }
    }

    return 0;
}