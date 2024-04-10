#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define SZ(a) a.size()
#define LL long long

#define PB push_back
#define MP make_pair

const LL mod = 1000000007;

int n,m,a,b;
vector<int> g[300000];
LL u[300000];
LL num[300000];
LL sz[300000];
LL res = 0;

LL dfs1(int v, int p)
{
    sz[v] = 1;
    num[v] = 1;
    FOR (i,0,g[v].size())
    if (g[v][i] != p)
    {
        int value = dfs1(g[v][i],v);
        res -= value*(n-sz[g[v][i]])%mod*u[v]%mod;
        num[v] -= value;
        sz[v] += sz[g[v][i]];
    }
    return num[v]%mod;
}

void dfs2(int v, int p, int val)
{
    res -= val%mod*u[v]%mod*sz[v]%mod;
    FOR (i,0,g[v].size())
    if (g[v][i] != p)
        dfs2(g[v][i],v,-val+num[v]+num[g[v][i]]);
}


int main()
{
    cin >> n;
    FOR (i,0,n) cin >> u[i];
    FOR (i,0,n-1)
    {
        cin >> a >> b;
        a--; b--;
        g[a].PB(b); g[b].PB(a);
    }
    dfs1(0,-1);
    dfs2(0,-1,0);
    FOR (i,0,n) res = (res+n*u[i])%mod;
    cout << (res%mod+mod)%mod;
}