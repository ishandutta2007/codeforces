#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long llong;

int n;
int nums[200111];

vector<int> divs[200111];
int cnts[200111][21];

llong ans = 1LL;

int main()
{
    int i,j;

    for (i=2;i<=200000;i++)
    {
        if (divs[i].empty())
        {
            for (j=i;j<=200000;j+=i)
            {
                divs[j].push_back(i);
            }
        }
    }

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        int num;
        scanf("%d", &num);

        for (j=0;j<divs[num].size();j++)
        {
            int cp = num;
            int cur = 1;

            while(cp % divs[num][j] == 0)
            {
                cnts[ divs[num][j] ][cur]++;
                cp /= divs[num][j];
                cur++;
            }
        }
    }

    for (i=2;i<=200000;i++)
    {
        for (j=1;;j++)
        {
            if (cnts[i][j] < n-1)
                break;

            ans *= (llong)i;
        }
    }

    printf("%lld\n", ans);

    return 0;
}