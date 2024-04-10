#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#define N 220
using namespace std;

set<int> a[N];
int c[N][N], o[N], u[N];

int Reduce(int *c, int n, int v)
{
    int i;
    set<int>::iterator k;

    for(i = 2; i <= n; i ++)
        if(!u[i] && a[i].count(v))
        {
            for(k = a[i].begin(); k != a[i].end(); ++ k)
                c[*k] --;
            break;
        }

    return i;
}

void DFS(int n, int x, int s)
{
    int i, j, t;
    vector<int> p;
    set<int> q;

    if(x == 1)
    {
        o[1] = s;
        for(i = 2; i <= n; i ++)
        {
            q.clear();
            for(j = 0; j < (signed)a[i].size(); j ++)
                q.insert(o[u[i] - j]);
            if(q != a[i])
                break;
        }
        if(i > n)
            throw 0;

        return;
    }

    for(i = 1; i <= n; i ++)
        if(i != s && c[x][i] == 1)
            p.push_back(i);
    if(p.empty() || p.size() > 1)
        return;

    // printf("ready %d %d\n", p[0], p.size() > 1 ? p[1] : -1);
    copy(c[x] + 1, c[x] + n + 1, c[x - 1] + 1);
    o[x] = p[0];
    // printf("at %d found %d\n", x, o[x]);
    t = Reduce(c[x - 1], n, o[x]);
    // for(i=1;i<=n;i++)cout<<c[x-1][i]<<' ';cout<<endl;
    u[t] = x;
    DFS(n, x - 1, s);
    u[t] = 0;

    return;
}

int main(void)
{
    int t, n, m, x;
    int i, j;

    cin >> t;
    while(t --)
    {
        cin >> n;
        for(i = 1; i <= n; i ++)
            c[n][i] = u[i] = 0;
        for(i = 2; i <= n; i ++)
        {
            cin >> m;
            a[i].clear();
            for(j = 0; j < m; j ++)
            {
                cin >> x;
                a[i].insert(x);
                c[n][x] ++;
            }
        }

        for(i = 1; i <= n; i ++)
            try
            {
                DFS(n, n, i);
            }
            catch(...)
            {
                for(i = 1; i <= n; i ++)
                    cout << o[i] << " \n"[i == n];
                break;
            }

    }

    return 0;
}
// lg