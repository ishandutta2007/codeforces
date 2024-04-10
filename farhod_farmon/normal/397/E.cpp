#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 300200;

using namespace std;

int n;
int tim;
int tin[N];
int tout[N];
int dep[N];
int mod = 1e9 + 7;
pair < int, int > t[4 * N];
vector < int > v[N];

void dfs(int x, int g)
{
    tin[x] = tout[x] = ++tim;
    dep[tin[x]] = g;
    for(auto y: v[x]){
        dfs(y, g - 1);
        tout[x] = tout[y];
    }
}

void push(int x)
{
    t[x * 2].fi += t[x].fi;
    t[x * 2].se += t[x].se;
    t[x * 2 + 1].fi += t[x].fi;
    t[x * 2 + 1].se += t[x].se;
    t[x * 2].fi %= mod;
    t[x * 2].se %= mod;
    t[x * 2 + 1].fi %= mod;
    t[x * 2 + 1].se %= mod;
    t[x].fi = t[x].se = 0;
}

void upd(int x, int l, int r, int tl, int tr, int f1, int f2)
{
    if(tl > tr)
        return;
    if(l == tl && r == tr){
        t[x].fi = (t[x].fi + f1) % mod;
        t[x].se = (t[x].se + f2) % mod;
        return;
    }
    push(x);
    int m = (l + r) / 2;
    upd(x * 2, l, m, tl, min(m, tr), f1, f2);
    upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, f1, f2);
}

int get(int x, int l, int r, int g)
{
    if(l == r){
        int ans = (1ll * t[x].se * dep[l]) % mod;
        ans = (t[x].fi + ans) % mod;
        return ans;
    }
    push(x);
    int m = (l + r) / 2;
    if(g <= m)
        return get(x * 2, l, m, g);
    else
        return get(x * 2 + 1, m + 1, r, g);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    sc("%d", &n);
    for(int i = 2; i <= n; i++){
        int x;
        sc("%d", &x);
        v[x].pb(i);
    }
    dfs(1, n);
    int q;
    sc("%d", &q);
    for(int i = 1; i <= q; i++){
        int t, v, x, k;
        sc("%d", &t);
        if(t == 1){
            sc("%d%d%d", &v, &x, &k);
            long long f = 1ll * x - 1ll * dep[tin[v]] * k;
            f = f % mod + mod;
            upd(1, 1, n, tin[v], tout[v], f % mod, k);
        }
        else{
            sc("%d", &v);
            pr("%d\n", get(1, 1, n, tin[v]));
        }
    }
}