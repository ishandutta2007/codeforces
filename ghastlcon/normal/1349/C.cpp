#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#define N 1020
using namespace std;

const int d[4][2] = 
{
    {0, 1},
    {1, 0},
    {-1, 0},
    {0, -1},
};

int n, m, a[N][N];
bool u[N][N];
int f[N][N];
queue<pair<int, int> > q;

void DFS(int x, int y, vector<pair<int, int> > &v)
{
    int i, p, q;

    u[x][y] = true;
    v.push_back(make_pair(x, y));

    for(i = 0; i < 4; i ++)
    {
        p = x + d[i][0];
        q = y + d[i][1];
        if(p > -1 && q > -1 && p < n && q < m && a[p][q] == a[x][y] && !u[p][q])
            DFS(p, q, v);
    }

    return;
}

void BFS(void)
{
    int i, x, y, s, t;

    for(; !q.empty(); q.pop())
    {
        x = q.front().first;
        y = q.front().second;
        for(i = 0; i < 4; i ++)
        {
            s = x + d[i][0];
            t = y + d[i][1];
            if(s > -1 && t > -1 && s < n && t < m && f[s][t] > f[x][y] + 1)
            {
                f[s][t] = f[x][y] + 1;
                q.push(make_pair(s, t));
            }
        }
    }

    return;
}

int main(void)
{
    int q, x, y;
    long long t;
    int i, j;
    vector<vector<pair<int, int> > > c;

    scanf("%d %d %d", &n, &m, &q);
    for(i = 0; i < n; i ++)
        for(j = 0; j < m; j ++)
        {
            scanf("%1d", &a[i][j]);
            f[i][j] = INT_MAX;
        }

    for(i = 0; i < n; i ++)
        for(j = 0; j < m; j ++)
            if(!u[i][j])
            {
                c.push_back(vector<pair<int, int> >());
                DFS(i, j, c.back());
            }
    // cout<<c.size()<<endl;

    memset(u, false, sizeof(u));
    for(i = 0; i < (signed)c.size(); i ++)
        if(c[i].size() > 1)
            for(j = 0; j < (signed)c[i].size(); j ++)
            {
                f[c[i][j].first][c[i][j].second] = 0;
                ::q.push(make_pair(c[i][j].first, c[i][j].second));
            }
    BFS();
    // for(i=0;i<n;i++){for(j=0;j<m;j++)cout<<f[i][j]<<' ';cout<<endl;}

    while(q --)
    {
        scanf("%d %d %I64d", &x, &y, &t);
        printf("%d\n", a[x - 1][y - 1] ^ (f[x - 1][y - 1] == INT_MAX ? 0 : (max(0LL, t - f[x - 1][y - 1]) & 1)));
    }

    return 0;
}