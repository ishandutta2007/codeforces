#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 400400;

using namespace std;

int n, m;
int tin[N];
int f[N];
int tim;
bool used[N], bridge[N], used2[N];
vector < pair < int, int > > v[N];
map < pair < int, int >, bool > edge;

void dfs(int x, int p)
{
    used[x] = true;
    tin[x] = f[x] = ++tim;
    for(auto yy: v[x]){
        int y = yy.fi;
        if(y == p)
            continue;
        if(used[y])
            f[x] = min(f[x], tin[y]);
        else{
            dfs(y, x);
            f[x] = min(f[x], f[y]);
            if(f[y] > tin[x]){
                bridge[yy.se] = true;
            }
        }
    }
}

int sz = 0, ans[N];
vector < int > g;

void dfs2(int x)
{
    if(used2[x])
        return;
    used2[x] = true;
    sz++;
    g.pb(x);
    for(auto y: v[x]){
        if(bridge[y.se])
            continue;
        if(edge[{x, y.fi}] || edge[{y.fi, x}])
            continue;
        edge[{x, y.fi}] = true;
        dfs2(y.fi);
    }
}

bool used3[N];

void dfs3(int x)
{
    if(used3[x])
        return;
    used3[x] = true;
    g.pb(x);
    for(auto y: v[x]){
        if(bridge[y.se] && !edge[{x, y.fi}])
            edge[{y.fi, x}] = true;
        dfs3(y.fi);
    }
}

int a[N];
int b[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    sc("%d%d", &n, &m);
    for(int i = 1; i <= m; i++){
        int x, y;
        sc("%d%d", &x, &y);
        v[x].pb({y, i});
        v[y].pb({x, i});
        a[i] = x;
        b[i] = y;
    }
    for(int i = 1; i <= n; i++){
        if(!used[i])
            dfs(i, -1);
    }
    int cnt = 0;
    int root = 0;
    for(int i = 1; i <= n; i++){
        if(used2[i])
            continue;
        sz = 0;
        g.clear();
        dfs2(i);
        if(sz > cnt)
            root = i;
        cnt = max(cnt, sz);
        for(auto x: g)
            ans[x] = sz;
    }
    dfs3(root);
    pr("%d\n", cnt);
    for(int i = 1; i <= m; i++){
        if(edge[{b[i], a[i]}])
            pr("%d %d\n", b[i], a[i]);
        else
            pr("%d %d\n", a[i], b[i]);
    }
}