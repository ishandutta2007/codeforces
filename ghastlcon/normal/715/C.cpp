#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <utility>
#define N 100020
using namespace std;

extern vector<pair<int, int> > e[N];
extern bool u[N];

namespace Center
{
    int f[N], g[N];
    vector<int> v;

    void DFS(int x, int p)
    {
        int i;

        v.push_back(x);
        f[x] = 1;
        g[x] = 0;
        for(i = 0; i < (signed)e[x].size(); i ++)
            if(!u[e[x].at(i).first] && e[x].at(i).first != p)
            {
                DFS(e[x].at(i).first, x);
                f[x] += f[e[x].at(i).first];
                g[x] = max(g[x], f[e[x].at(i).first]);
            }

        return;
    }

    int Center(int x)
    {
        int i, o;

        v.clear();
        DFS(x, x);
        for(i = o = 0; i < (signed)v.size(); i ++)
            if(max(g[v.at(i)], f[x] - f[v.at(i)]) < max(g[v.at(o)], f[x] - f[v.at(o)]))
                o = i;

        return v.at(o);
    }
}

vector<pair<int, int> > e[N];
int m, p[2][N];
long long o;
bool u[N];
int d[N], f[N], g[N];
map<int, int> s[2][N], w[2];

void ExGCD(int a, int b, int &x, int &y)
{
    if(!b)
    {
        x = 1;
        y = 0;
    }
    else
    {
        ExGCD(b, a % b, y, x);
        y -= x * (a / b);
    }

    return;
}

int Inverse(int k)
{
    int x, y;

    ExGCD(k, m, x, y);

    return (x % m + m) % m;
}

void DFS(int x, int p, int k)
{
    int i, v;

    v = (long long)g[x] * ::p[1][d[x] + 1] % m;
    o += (!f[x]) + (!g[x]);
    // printf("%d : gen %d, %d, check %d %d %d (%d, %d)\n", x+1,!f[x], !g[x], v,w[0][(m - v) % m],w[1][f[x]],f[x],g[x]);
    o += w[0][(m - v) % m] + w[1][(m - f[x]) % m];
    s[0][k][f[x]] ++;
    s[1][k][v   ] ++;
    for(i = 0; i < (signed)e[x].size(); i ++)
    {
        v = e[x].at(i).first;
        if(!u[v] && v != p)
        {
            d[v] = d[x] + 1;
            f[v] = ((long long)f[x] + (long long)e[x].at(i).second * ::p[0][d[v]] % m) % m;
            g[v] = ((long long)g[x] * 10 % m + e[x].at(i).second) % m;
            DFS(v, x, k);
        }
    }

    return;
}

void DAQ(int x)
{
    int i, v;
    map<int, int>::iterator t;

    x = Center::Center(x);
    u[x] = true;
    // printf("center %d\n", x + 1);

    w[0].clear();
    w[1].clear();
    for(i = 0; i < (signed)e[x].size(); i ++)
        if(!u[v = e[x].at(i).first])
        {
            d[v] = 0;
            f[v] = g[v] = e[x].at(i).second % m;
            s[0][v].clear();
            s[1][v].clear();
            DFS(v, v, v);
            // printf("center %d, to %d, = %d\n", x + 1, v + 1);
            // o += s[0][v][0] + s[1][v][0];

            if(w[0].size() < s[0][v].size())
                swap(w[0], s[0][v]);
            if(w[1].size() < s[1][v].size())
                swap(w[1], s[1][v]);
            for(t = s[0][v].begin(); t != s[0][v].end(); ++ t)
                w[0][t -> first] += t -> second;
            for(t = s[1][v].begin(); t != s[1][v].end(); ++ t)
                w[1][t -> first] += t -> second;
        }

    for(i = 0; i < (signed)e[x].size(); i ++)
        if(!u[e[x].at(i).first])
            DAQ(e[x].at(i).first);

    return;
}

int main(void)
{
    int n, u, v, w;
    int i;

    scanf("%d %d", &n, &m);
    for(i = 1; i < n; i ++)
    {
        scanf("%d %d %d", &u, &v, &w);
        e[u].push_back(make_pair(v, w));
        e[v].push_back(make_pair(u, w));
    }
    for(i = p[0][0] = p[1][0] = 1; i < N; i ++)
    {
        p[0][i] = (long long)p[0][i - 1] * 10 % m;
        p[1][i] = Inverse(p[0][i]);
    }
    // printf("inv %d\n", p[1][1]);

    DAQ(0);
    printf("%lld\n", o);

    return 0;
}