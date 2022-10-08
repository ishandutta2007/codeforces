#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
typedef long long llong;

int t;
int n;
vector<int> positions[200111];
int nums[200111];

vector<int> activeSet;
vector<int> nextSet;

vector<int> ans;

int main()
{
    int test;
    int i, j;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%d", &n);

        for (i=0;i<=n+2;i++)
        {
            positions[i].clear();
        }

        bool isSmall = false;
        for (i=1;i<=n;i++)
        {
            scanf("%d", &nums[i]);

            if (nums[i] == n + 1)
                isSmall = true;

            positions[ nums[i] ].push_back(i);
        }

        activeSet.clear();
        activeSet.push_back(0);
        activeSet.push_back(n+1);

        int k = 0;
        ans.clear();
        while(activeSet.size() > 0)
        {
            vector<int> nextAns;

            nextSet.clear();
            int special = -1;
            for (int val : activeSet)
            {
                if (positions[val].size() > 0)
                    special = val;
                for (int pos : positions[val])
                {
                    nextSet.push_back(pos);
                    nextAns.push_back(pos);

                    if (isSmall)
                        k = max(k, pos);
                }
            }
            for (i = (int)ans.size() - 1; i >= 0; i--)
            {
                if (ans[i] == special)
                {
                    swap(ans[i], ans[ ans.size() - 1 ]);
                    break;
                }
            }
            for (i=0;i<nextAns.size();i++)
            {
                ans.push_back(nextAns[i]);
            }

            activeSet = nextSet;
            isSmall = !isSmall;
        }

        printf("%d\n", k);
        for (i=0;i<ans.size();i++)
        {
            if (i != 0)
                printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }

    return 0;
}