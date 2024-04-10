#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#define N 200020
using namespace std;

int a[N];
vector<int> v[N];
int g[N];

int main(void)
{
    int t, n, m;
    int i, j, o, w;
    vector<int> s;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d", &n);
        s.clear();
        for(i = 1; i <= n; i ++)
        {
            scanf("%d", &a[i]);
            s.push_back(a[i]);
        }
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end());
        m = (int)s.size();

        for(i = 1; i <= n; i ++)
        {
            a[i] = (int)(lower_bound(s.begin(), s.end(), a[i]) - s.begin() + 1);
            v[a[i]].push_back(i);
        }
        for(i = 1; i <= m; i ++)
            g[i] = g[i - 1] + (int)v[i].size();

        for(i = j = 1, o = 0; i <= m; i ++)
        {
            for(j = max(j, i + 1); j <= m && v[j].front() > v[j - 1].back(); j ++)
                ;
            w = g[j - 1] - g[i - 1];
            if(i != 1)
                w += (int)(lower_bound(v[i - 1].begin(), v[i - 1].end(), v[i].front()) - v[i - 1].begin());
            if(j != m + 1)
                w += (int)(v[j].end() - upper_bound(v[j].begin(), v[j].end(), v[j - 1].back()));
            o = max(o, w);
            // printf("%d(%d) - %d(%d) : %d\n", i, s[i - 1], j - 1, s[j - 2], w);
        }
        printf("%d\n", n - o);

        for(i = 1; i <= m; i ++)
            v[i].clear();
    }

    return 0;
}