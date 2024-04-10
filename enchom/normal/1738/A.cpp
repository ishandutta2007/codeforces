#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long llong;

int t;
int n;

vector<int> S[2];
int tps[200111];

int main()
{
    int test;
    int i, j;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        S[0].clear();
        S[1].clear();

        scanf("%d", &n);

        for (i=1;i<=n;i++)
        {
            scanf("%d", &tps[i]);
        }

        for (i=1;i<=n;i++)
        {
            int strength;
            scanf("%d", &strength);

            S[ tps[i] ].push_back(strength);
        }

        sort(S[0].begin(), S[0].end());
        reverse(S[0].begin(), S[0].end());
        sort(S[1].begin(), S[1].end());
        reverse(S[1].begin(), S[1].end());

        llong ans = 0;
        for (int start = 0; start <= 1; start++)
        {
            if (S[start].empty())
                continue;

            int prevType = start;
            int p[2] = {0, 0};
            llong curAns = 0;
            int savedLast = S[start].back();

            curAns = S[start].back();
            //printf("Start by taking %d\n", S[start].back());
            S[start].pop_back();

            int cur = start ^ 1;

            while(p[0] < S[0].size() || p[1] < S[1].size())
            {
                if (p[cur] < S[cur].size())
                {
                    curAns += S[cur][ p[cur] ];

                    //printf("Now take %d\n", S[cur][ p[cur] ]);

                    if (prevType != cur)
                        curAns += S[cur][ p[cur] ];

                    p[cur]++;
                    prevType = cur;
                }

                cur ^= 1;
            }

            ans = max(ans, curAns);

            S[start].push_back(savedLast);
        }

        printf("%lld\n", ans);
    }

    return 0;
}