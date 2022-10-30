#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#define N 200020
using namespace std;

int n, l[N], r[N];
vector<pair<int, int> > a[N];
int o[N];
pair<int, int> f[N << 1];

void SetSegwin(int p, int v, int d, int n, bool k)
{
    p += n;
    if(k || v > f[p].first)
    {
        f[p].first = v;
        f[p].second = d;
    }
    while(p >>= 1)
        f[p] = max(f[p << 1], f[p << 1 | 1]);

    return;
}

int MaxSegwin(int l, int r, int n, int v)
{
    pair<int, int> o;

    o = make_pair(0, 0);
    for(l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
    {
        if(l & 1)
            o = max(o, f[l ++]);
        if(r & 1)
            o = max(o, f[-- r]);
    }

    return o.first >= v ? o.second : 0;
}

void CDQ(int l, int r)
{
    int i, p, q, m;
    vector<pair<int, int> > x;

    if(l >= r)
        return;

    m = (l + r) >> 1;
    CDQ(l    , m);
    CDQ(m + 1, r);

    for(i = l; i <= m; i ++)
        x.push_back(make_pair(::l[i], i));
    for(i = m + 1; i <= r; i ++)
        x.push_back(make_pair(o[i], i));
    sort(x.begin(), x.end());

    for(i = 0; i < (signed)x.size(); i ++)
    {
        p = x[i].second;
        if(p <= m)
            SetSegwin(o[p], ::r[p], p, n, false);
        else if((q = MaxSegwin(::l[p], ::r[p], n, x[i].first)))
        {
            printf("NO\n");
            for(i = 1; i <= n; i ++)
                printf("%d%c", o[i], " \n"[i == n]);
            swap(o[p], o[q]);
            for(i = 1; i <= n; i ++)
                printf("%d%c", o[i], " \n"[i == n]);

            exit(0);
        }
    }
    for(i = 0; i < (signed)x.size(); i ++)
        if(x[i].second <= m)
            SetSegwin(o[x[i].second], 0, 0, n, true);

    return;
}

int main(void)
{
    int i, j;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;

    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
    {
        scanf("%d %d", &l[i], &r[i]);
        a[l[i]].push_back(make_pair(r[i], i));
    }

    for(i = 1; i <= n; i ++)
    {
        for(j = 0; j < (signed)a[i].size(); j ++)
            q.push(a[i][j]);

        if(q.top().first < i)
            throw;
        o[q.top().second] = i;
        q.pop();
    }

    CDQ(1, n);
    printf("YES\n");
    for(i = 1; i <= n; i ++)
        printf("%d%c", o[i], " \n"[i == n]);

    return 0;
}