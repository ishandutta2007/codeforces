#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#define N 10020
#define M 21
using namespace std;

int n, m;
bool a[N];
int b[N];
int f[1 << M | 1], g[M][N];
vector<int> v;
queue<int> q;

void BFS(int s, int k)
{
    int i;

    for(i = 0; i <= n; i ++)
        g[k][i] = N;
    g[k][s] = 0;

    for(q.push(s); !q.empty(); q.pop())
    {
        s = q.front();
        for(i = 0; i < m; i ++)
        {
            if(s - b[i] > -1 && g[k][s - b[i]] > g[k][s] + 1)
            {
                g[k][s - b[i]] = g[k][s] + 1;
                q.push(s - b[i]);
            }
            if(s + b[i] <= n && g[k][s + b[i]] > g[k][s] + 1)
            {
                g[k][s + b[i]] = g[k][s] + 1;
                q.push(s + b[i]);
            }
        }
    }

    return;
}

int main(void) // z.cpp
{
    int k, p;
    int i, x, y;

    cin >> n >> k >> m;
    while(k --)
    {
        cin >> p;
        a[-- p] = true;
    }
    for(i = 0; i < m; i ++)
        cin >> b[i];
    for(i = n; i > 0; i --)
        a[i] ^= a[i - 1];
    // for(i=0;i<=n;i++)cout<<a[i]<<' ';cout<<endl;

    for(i = 0; i <= n; i ++)
        if(a[i])
        {
            BFS(i, v.size());
            v.push_back(i);
            // cout<<"pos "<<i<<endl;
            // for(int j=0;j<n;j++)cout<<g[v.size()-1][j]<<' ';cout<<endl;
        }
    // cout<<v.size()<<endl;
    // for(i=0;i<v.size();i++)cout<<v[i]<<' ';cout<<endl;

    for(i = 1; i < (1 << v.size()); i ++)
    {
        f[i] = N;
        if(!__builtin_parity(i))
            for(y = (x = __builtin_ctz(i)) + 1; y < (signed)v.size(); y ++)
                if(i & (1 << y))
                    f[i] = min(f[i], f[i ^ (1 << x) ^ (1 << y)] + g[x][v.at(y)]);
    }
    cout << (f[(1 << v.size()) - 1] == N ? -1 : f[(1 << v.size()) - 1]) << endl;

    return 0;
}