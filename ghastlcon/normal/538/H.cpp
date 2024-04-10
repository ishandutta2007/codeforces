#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <vector>
#include <utility>
#define N 100020
using namespace std;

int a[N], b[N];
vector<int> e[N];
int c[N];
vector<int> p;
char o[N];

void NoSolution(void)
{
    printf("IMPOSSIBLE\n");

    exit(0);
}

bool Interval(int l, int r, int x)
{
    return l <= x && x <= r;
}

void DFS(int x, int k)
{
    int i;

    if(c[x])
    {
        if(c[x] != k)
            NoSolution();

        return;
    }
    c[x] = k;
    p.push_back(x);

    for(i = 0; i < (signed)e[x].size(); i ++)
        DFS(e[x][i], 3 - k);

    return;
}

int main(void)
{
    int l, r, s, t, n, m;
    int i, j, u, v;

    scanf("%d %d %d %d", &l, &r, &n, &m);
    for(i = 1; i <= n; i ++)
        scanf("%d %d", &a[i], &b[i]);
    while(m --)
    {
        scanf("%d %d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }

    u = *min_element(b + 1, b + n + 1);
    v = *max_element(a + 1, a + n + 1);
    for(; u + v < l; v ++)
        ;
    for(; u + v > r; u --)
        ;
    if(u < 0 || v < 0)
        NoSolution();

    for(i = 1; i <= n; i ++)
        if(!c[i])
        {
            p.clear();
            DFS(i, 1);

            l = s = INT_MIN;
            r = t = INT_MAX;
            for(j = 0; j < (signed)p.size(); j ++)
                if(c[p[j]] == 1)
                {
                    l = max(l, a[p[j]]);
                    r = min(r, b[p[j]]);
                }
                else
                {
                    s = max(s, a[p[j]]);
                    t = min(t, b[p[j]]);
                }
            // printf("%d : %d-%d, %d-%d\n", i, l, r, s, t);
            if(l > r || s > t)
                NoSolution();

            if(Interval(l, r, u) && Interval(s, t, v))
                for(j = 0; j < (signed)p.size(); j ++)
                    o[p[j]] = c[p[j]] + 48;
            else if(Interval(s, t, u) && Interval(l, r, v))
                for(j = 0; j < (signed)p.size(); j ++)
                    o[p[j]] = 51 - c[p[j]];
            else
                NoSolution();
        }
    printf("POSSIBLE\n%d %d\n%s\n", u, v, o + 1);

    return 0;
}