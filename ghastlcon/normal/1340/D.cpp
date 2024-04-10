#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <utility>
#define N 100020
using namespace std;

int t;
vector<int> e[N];
vector<pair<int, int> > o;

void DFS(int x, int p, int t)
{
    int i, r, c, k;

    o.push_back(make_pair(x, t));
    k = (int)e[x].size() - (x != 1);
    r = t;

    for(i = c = 0; i < (signed)e[x].size(); i ++)
        if(e[x][i] != p)
        {
            c ++;
            if(t + c > ::t)
            {
                c --;
                o.push_back(make_pair(x, r - 1 - (k - c)));
                t = r - 1 - (k - c);
                c = 1;
            }
            DFS(e[x][i], x, t + c);
            o.push_back(make_pair(x, t + c));

            // if(x == 1 || t + 1 + k <= ::t)
            // {
            //     DFS(e[x][i], x, t + c);
            //     o.push_back(make_pair(x, t + c));
            // }
            // else
            // {
            //     if(t + c <= ::t)
            // }
        }
    if(x != 1 && t + c != r - 1)
        o.push_back(make_pair(x, r - 1));

    return;
}

int main(void)
{
    int n, u, v;
    int i;

    scanf("%d", &n);
    for(i = 1; i < n; i ++)
    {
        scanf("%d %d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(i = 1; i <= n; i ++)
        t = max(t, (int)e[i].size());
    DFS(1, 1, 0);

    printf("%d\n", (int)o.size());
    for(i = 0; i < (signed)o.size(); i ++)
        printf("%d %d\n", o[i].first, o[i].second);

    return 0;
}
// lg