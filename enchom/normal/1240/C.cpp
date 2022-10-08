#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long llong;

int t;
int n,k;
vector< pair<int,int> > Graph[500111];

llong mem[500111][2];

llong solve(int ver, int dad, int useDad)
{
    if (mem[ver][useDad] != -1)
        return mem[ver][useDad];

    int i;
    vector<llong> gains;
    llong ans = 0;

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Graph[ver][i].first == dad)
            continue;

        llong noDad = solve(Graph[ver][i].first, ver, 0);
        llong withDad = solve(Graph[ver][i].first, ver, 1);

        ans += (llong)noDad;

        gains.push_back(withDad - noDad + (llong)Graph[ver][i].second);
    }

    sort(gains.begin(), gains.end());

    int quota = k - useDad;

    for (i=(int)gains.size()-1;i>=0;i--)
    {
        if (quota <= 0)
            break;

        if (gains[i] > 0)
        {
            ans += (llong)gains[i];
            quota--;
        }
        else
            break;
    }

    mem[ver][useDad] = ans;

    return ans;
}

int main()
{
    int i,j;
    int test;

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        scanf("%d %d",&n,&k);

        for (i=1;i<=n;i++)
        {
            Graph[i].clear();
            mem[i][0] = -1;
            mem[i][1] = -1;
        }

        for (i=1;i<n;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            Graph[a].push_back(make_pair(b,c));
            Graph[b].push_back(make_pair(a,c));
        }

        printf("%lld\n",solve(1, 0, 0));
    }

    return 0;
}