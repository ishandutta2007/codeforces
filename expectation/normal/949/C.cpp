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

const LL mod = 1000000007;

bool ok[200000];
int n,m,H;
int h[200000];
int c[200000];
bool bc[200000];
int sz[200000];
vector<int> g[200000], gr[200000];
vector<char> used;
vector<int> order;

void dfs1 (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i)
        if (!used[ g[v][i] ])
            dfs1 (g[v][i]);
    order.push_back (v);
}

int color = 0;
void dfs2 (int v) {
    used[v] = true;
    sz[color]++;
    c[v] = color;
    for (size_t i=0; i<gr[v].size(); ++i)
        if (!used[ gr[v][i] ])
            dfs2 (gr[v][i]);
}

int main()
{
    scanf("%d%d%d",&n,&m,&H);
    FOR (i,0,n) scanf("%d",h+i);
    FOR (i,0,m)
    {
        int a, b;
        scanf("%d%d",&a,&b);a--;b--;
        if ((h[a]+1)%H == h[b]) g[a].push_back(b), gr[b].push_back(a);
        if ((h[b]+1)%H == h[a]) g[b].push_back(a), gr[a].push_back(b);
    }
    used.assign(n, false);
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs1 (i);
    used.assign (n, false);
    for (int i=0; i<n; ++i) {
        int v = order[n-1-i];
        if (!used[v]) {
            dfs2 (v);
            color++;
        }
    }
    FOR (i,0,n)
    FOR (j,0,g[i].size())
    if (c[i] != c[g[i][j]]) bc[c[i]] = 1;
    int ansc = -1;
    FOR (i,0,color)
    if (!bc[i] && (ansc == -1 || sz[i] < sz[ansc])) ansc = i;
    cout <<sz[ansc] << "\n";
    FOR (i,0,n)
    if (c[i] == ansc) cout << i+1<<" ";
}