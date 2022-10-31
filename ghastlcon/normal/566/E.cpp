#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <bitset>
#include <utility>
#define N 1001
using namespace std;

bitset<N> a[N], b[N];
vector<pair<int, int> > o;
bool u[N];

inline void Answer(int u, int v)
{
    o.push_back(make_pair(min(u, v), max(u, v)));

    return;
}

bitset<N> Chip(int x, int n)
{
    int i;
    bitset<N> o;

    o.flip();
    for(i = 1; i <= n; i ++)
        if(a[i].test(x) && a[i].count() < o.count())
            o = a[i];

    return o;
}

int main(void)
{
    int n, l, x, y;
    int i, j;
    bitset<N> t;

    scanf("%d", &n);
    if(n == 2)
    {
        printf("1 2\n");
        return 0;
    }

    for(i = 1; i <= n; i ++)
    {
        scanf("%d", &l);
        while(l --)
        {
            scanf("%d", &x);
            a[i].set(x);
        }
    }

    for(i = 1; i <= n; i ++)
        for(j = 1; j < i; j ++)
        {
            t = a[i] & a[j];
            if(t.count() == 2)
            {
                y = (int)t._Find_next(x = (int)t._Find_first());
                Answer(x, y);
                b[x].set(y);
                b[y].set(x);
                u[x] = u[y] = true;
                // printf("%d %d\n", x, y);
            }
        }
    if(o.empty())
    {
        for(i = 1; i < n; i ++)
            printf("%d %d\n", i, n);
        return 0;
    }

    for(i = 1, l = 0; i <= n; i ++)
        if(u[i])
        {
            l ++;
            b[i].set(i);
        }

    if(l < 2)
        throw;
    else if(l == 2)
    {
        for(i = 1; i <= n; i ++)
            if(!u[i])
            {
                t = Chip(i, n);
                for(j = i; j <= n; j ++)
                    if(!u[j])
                        Answer(j, Chip(i, n) == Chip(j, n) ? x : y);
                break;
            }
    }
    else
        for(i = 1; i <= n; i ++)
            if(!u[i])
            {
                t = Chip(i, n);
                for(j = 1; j <= n; j ++)
                    if(!u[j])
                        t.reset(j);
                for(j = 1; j <= n; j ++)
                    if(u[j] && t == b[j])
                    {
                        Answer(i, j);
                        break;
                    }
            }

    sort(o.begin(), o.end());
    o.erase(unique(o.begin(), o.end()), o.end());
    for(i = 0; i < n - 1; i ++)
        printf("%d %d\n", o[i].first, o[i].second);

    return 0;
}