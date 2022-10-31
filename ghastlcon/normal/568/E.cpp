#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>
#include <set>
#include <utility>
#define N 100020
using namespace std;

int a[N], b[N];
int f[N], p[N];
vector<pair<int, int> > g[N];
multiset<int> h;

int main(void)
{
    int n, m;
    int i, j, k, t;

    scanf("%d", &n);
    for(i = 0; i < n; i ++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for(i = 0; i < m; i ++)
    {
        scanf("%d", &b[i]);
        h.insert(b[i]);
    }
    sort(b, b + m);

    fill(f + 1, f + n + 1, INT_MAX);
    for(i = 0; i < n; i ++)
        if(a[i] == -1)
        {
            for(j = k = 0; k <= n && j < m; j ++)
            {
                for(; k <= n && f[k] < b[j]; k ++)
                    ;
                p[j] = k;
            }

            for(k = 0; k < j; k ++)
                if(b[k] < f[p[k]])
                    g[p[k]].push_back(make_pair(i, f[p[k]] = b[k]));
        }
        else
        {
            k = (int)(lower_bound(f, f + n + 1, a[i]) - f);
            g[k].push_back(make_pair(i, f[k] = a[i]));
        }
    // for(i = 0; i <= n; i ++) cout << f[i] << ' '; cout << endl;

    for(k = n; f[k] == INT_MAX; k --)
        ;
    for(i = N; k >= 1; k --)
    {
        t = (int)(upper_bound(g[k].begin(), g[k].end(), make_pair(i, -1)) - g[k].begin()) - 1;
        i = g[k][t].first;
        if(a[i] == -1)
        {
            a[i] = g[k][t].second;
            h.erase(h.find(g[k][t].second));
        }
        // printf("%d : time %d\n", k, i);
    }

    for(i = 0; i < n; i ++)
    {
        if(a[i] == -1)
        {
            a[i] = *h.begin();
            h.erase(h.begin());
        }
        printf("%d%c", a[i], " \n"[i == n - 1]);
    }

    return 0;
}