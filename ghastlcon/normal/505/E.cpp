#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#define N 100020
using namespace std;

int n, m, k, p;
int h[N], a[N];
long long f[N];

bool Solve(long long v)
{
    int i, j;
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > q;
    pair<long long, int> t;

    for(i = 0; i < n; i ++)
    {
        f[i] = v;
        if(f[i] - (long long)a[i] * m < h[i])
            q.push(make_pair(f[i] / a[i], i));
    }

    for(i = 0; i < m; i ++)
        for(j = 0; j < k; j ++)
        {
            if(q.empty())
                return true;
            t = q.top();
            q.pop();

            if(t.first <= i)
                return false;

            f[t.second] += p;
            if(f[t.second] - (long long)a[t.second] * m < h[t.second])
                q.push(make_pair(f[t.second] / a[t.second], t.second));
        }

    return q.empty();
}

int main(void)
{
    int i;
    long long l, m, r;

    scanf("%d %d %d %d", &n, &::m, &k, &p);
    for(i = 0; i < n; i ++)
        scanf("%d %d", &h[i], &a[i]);

    for(l = -1, r = LLONG_MAX >> 2; l + 1 < r; )
    {
        m = (l + r) >> 1;
        if(Solve(m))
            r = m;
        else
            l = m;
    }
    printf("%I64d\n", r);

    return 0;
}