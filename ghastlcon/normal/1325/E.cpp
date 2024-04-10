#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <utility>
#define N 1000020
#define M 1020
using namespace std;

vector<pair<int, int> > e[N];
vector<int> v;

int BFS(int s)
{
    static int q[N], d[N];
    static bool u[N];
    int i, j, o, l, r;

    for(i = 0; i < (signed)v.size(); i ++)
    {
        d[v[i]] = N;
        for(j = 0; j < (signed)e[v[i]].size(); j ++)
            u[e[v[i]][j].second] = false;
    }

    // printf("start %d\n", s);
    l = r = d[s] = 0;
    for(o = N, q[r ++] = s; l < r; l ++)
    {
        s = q[l];
        for(i = 0; i < (signed)e[s].size(); i ++)
            if(!u[e[s][i].second])
            {
                u[e[s][i].second] = true;
                if(d[e[s][i].first] != N)
                    o = min(o, d[s] + d[e[s][i].first] + 1);
                else
                {
                    d[e[s][i].first] = d[s] + 1;
                    q[r ++] = e[s][i].first;
                }
            }
    }

    return o;
}

int main(void)
{
    int n, x, p, q;
    int i, j, k;

    scanf("%d", &n);
    for(i = 0; i < n; i ++)
    {
        scanf("%d", &x);
        p = q = 0;
        for(j = 2; j * j <= x; j ++)
        {
            for(k = 0; !(x % j); k ++)
                x /= j;
            if(k & 1)
                (p ? q : p) = j;
        }
        if(x != 1)
            (p ? q : p) = x;

        if(!p && !q)
        {
            printf("1\n");

            return 0;
        }
        if(!q)
            q = 1;

        e[p].push_back(make_pair(q, i));
        e[q].push_back(make_pair(p, i));
        v.push_back(p);
        v.push_back(q);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(i = 0, p = n + 1; i < (signed)v.size() && v[i] < M; i ++)
        p = min(p, BFS(v[i]));
    printf("%d\n", p == n + 1 ? -1 : p);

    return 0;
}