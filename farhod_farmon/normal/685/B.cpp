#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

const int N = 300033;

using namespace std;

int n, s[N], q, ans, l, f[N], in[N], pre[N];
vector < int > v[N], pa[N];

void dfs(int x, int p)
{
    s[x] = 1;
    pre[x] = p;
    bool b = false;
    for(int i = 0; i < v[x].size(); i++){
        int y = v[x][i];
        if(y == p)
            continue;
        dfs(y, x);
        s[x] += s[y];
    }
    for(int i = 0; i < v[x].size(); i++){
        int y = v[x][i];
        if(y == p)
            continue;
        if(s[y] - 1 >= (s[x] - 1) / 2){
            f[x] = f[y];
            in[x] = in[y];
            pa[f[x]].pb(x);
            b = true;
        }
    }
    if(!b){
        f[x] = ++l;
        pa[l].pb(x);
        in[x] = x;
    }
}

bool can(int x, int y)
{
    int l = 0, r = pa[y].size() - 1;
    while(l < r){
        int m = (l + r) / 2;
        if(s[pa[y][m]] <= x)
            l = m + 1;
        else
            r = m;
    }
    ans = pa[y][l];
    return s[ans] > x;
}

void tr(int x, int y)
{
    if(!can(y, f[x]))
        ans = -1;
    else
        return;
    for(int i = 0; i < v[x].size(); i++){
        if(ans != -1)
            return;
        int y = v[x][i];
        if(y == pre[x])
            continue;
        if(f[x] == f[y])
            tr(in[x], x);
        else
            tr(y, x);
    }
}

int main()
{
    //fin
    //fout
    sc("%d%d", &n, &q);
    for(int i = 2; i <= n; i++){
        int x;
        sc("%d", &x);
        v[i].pb(x);
        v[x].pb(i);
    }
    dfs(1, 0);
    //return 0;
    for(int i = 1; i <= q; i++){
        int x;
        sc("%d", &x);
        ans = -1;
        tr(x, s[x] / 2);
        pr("%d\n", ans);
    }
}