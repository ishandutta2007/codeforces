#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>
#include <utility>
#define N 200020
using namespace std;

int a[N];
vector<pair<int, int> > v;
long long f[N], g[N], s[2][N];

int main(void)
{
    int n, m, k;
    int i, j;
    long long o;

    scanf("%d %d", &n, &k);
    m = n;
    for(i = 0; i < n; i ++)
        scanf("%d", &a[i]);

    sort(a, a + n);
    v.push_back(make_pair(0, 0));
    for(i = 0; i < n; i = j)
    {
        for(j = i; j < n && a[j] == a[i]; j ++)
            ;
        v.push_back(make_pair(a[i], j - i));
    }
    n = (signed)v.size() - 1;
    v.push_back(make_pair(0, 0));

    for(i = 1; i <= n; i ++)
    {
        s[0][i] = s[0][i - 1] + v[i].second;
        f[i] = f[i - 1] + (long long)(v[i].first - v[i - 1].first) * s[0][i - 1];
    }
    for(i = n; i >= 1; i --)
    {
        s[1][i] = s[1][i + 1] + v[i].second;
        g[i] = g[i + 1] + (long long)(v[i + 1].first - v[i].first) * s[1][i + 1];
    }

    for(i = 1, o = LLONG_MAX; i <= n; i ++)
    {
        if(v[i].second >= k)
            o = 0;
        else
        {
            if(s[0][i] >= k)
                o = min(o, f[i] - (s[0][i] - k));
            if(s[1][i] >= k)
                o = min(o, g[i] - (s[1][i] - k));
            o = min(o, f[i] + g[i] - (m - k));
        }
    }
    printf("%I64d\n", o);

    return 0;
}