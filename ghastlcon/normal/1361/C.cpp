#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <tuple>
#define N 1000020
using namespace std;

int n, a[N], b[N];
vector<tuple<int, int, int> > e[N];
int u[N], r[N];
vector<int> o;

void DFS(int x)
{
    int k;

    // printf("%d %d\n",x,p);
    for(; r[x] < (signed)e[x].size(); r[x] ++)
    {
        k = r[x];
        if(!u[get<1>(e[x][k])])
        {
            u[get<1>(e[x][k])] = get<2>(e[x][k]);
            // printf("%d->%d(%d) %d\n",x,get<0>(e[x][k]),get<1>(e[x][k])+1,get<2>(e[x][k]));
            // printf("dfs ? %d (%d->%d) : %d\n", k, x, e[x][k].first, get<1>(e[x][k]));
            DFS(get<0>(e[x][k]));
            o.push_back(get<1>(e[x][k]));
        }
    }

    return;
}

bool Check(int v)
{
    int i;
    vector<int> t;

    for(i = 0; i < n * 2; i ++)
    {
        b[i] = a[i] & ((1 << v) - 1);
        t.push_back(b[i]);
    }
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    for(i = 0; i < n * 2; i ++)
    {
        b[i] = (int)(lower_bound(t.begin(), t.end(), b[i]) - t.begin());
        e[b[i]].clear();
    }
    for(i = 0; i < n * 2; i ++)
        if(i & 1)
        {
            e[b[i]].push_back(make_tuple(b[i ^ 1], i, 1));
            e[b[i ^ 1]].push_back(make_tuple(b[i], i, 2));
        }

    for(i = 0; i < n * 2; i ++)
        if(e[b[i]].size() & 1)
            return false;

    o.clear();
    fill(r, r + t.size(), 0);
    fill(u, u + n * 2, 0);
    DFS(b[0]);

    // printf("total %d\n",(int)o.size());

    return (signed)o.size() == n;
}

int main(void)
{
    int i;
    int l, m, r;

    scanf("%d", &n);
    for(i = 0; i < n * 2; i ++)
        scanf("%d", &a[i]);

    // cout<<Check(2)<<endl;
    // return 0;
    for(l = 0, r = 21; l + 1 < r; )
        if(Check(m = (l + r) / 2))
            l = m;
        else
            r = m;

    Check(l);
    printf("%d\n", l);
    for(i = n - 1; i > -1; i --)
    {
        if(u[o[i]] == 1)
            printf("%d %d ", o[i] + 1, (o[i] ^ 1) + 1);
        else
            printf("%d %d ", (o[i] ^ 1) + 1, o[i] + 1);
    }
    printf("\n");

    return 0;
}