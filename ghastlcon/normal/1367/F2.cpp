#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <utility>
#define N 200020
using namespace std;

int a[N];
vector<int> v[N];
int g[N];

int main(void)
{
    int t, n, m;
    int i, j, k, o, w;
    vector<int> s;
    vector<pair<int, bool> > h;

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

            if(i < m)
            {
                h.clear();
                for(k = 0; k < (signed)v[i].size(); k ++)
                    h.push_back(make_pair(v[i][k], false));
                for(k = 0; k < (signed)v[i + 1].size(); k ++)
                    h.push_back(make_pair(v[i + 1][k], true));
                sort(h.begin(), h.end());

                w = (int)v[i + 1].size();
                o = max(o, w);
                for(k = 0; k < (signed)h.size(); k ++)
                {
                    if(h[k].second)
                        w --;
                    else
                        w ++;
                    o = max(o, w);
                }
            }
        }
        printf("%d\n", n - o);

        for(i = 1; i <= m; i ++)
            v[i].clear();
    }

    return 0;
}