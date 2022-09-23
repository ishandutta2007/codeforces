#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

struct seg
{
        int n;
        vector < long long > t, lz;
        seg(){}
        void init(int _n)
        {
                n = _n;
                t.resize(4 * n);
                lz.resize(4 * n);
                for(int i = 0; i < 4 * n; i++){
                        t[i] = lz[i] = 0;
                }
        }
        void push(int x)
        {
                if(lz[x]){
                        t[x * 2] += lz[x];
                        lz[x * 2] += lz[x];
                        t[x * 2 + 1] += lz[x];
                        lz[x * 2 + 1] += lz[x];
                        lz[x] = 0;
                }
        }
        void upd(int x, int tl, int tr, long long y, int l, int r)
        {
                if(tl > tr){
                        return;
                } else if(l == tl && r == tr){
                        t[x] += y;
                        lz[x] += y;
                        return;
                }
                push(x);
                int m = (l + r) / 2;
                upd(x * 2, tl, min(m, tr), y, l, m);
                upd(x * 2 + 1, max(m + 1, tl), tr, y, m + 1, r);
                t[x] = max(t[x * 2], t[x * 2 + 1]);
        }
        long long get(int x, int tl, int tr, int l, int r)
        {
                if(tl > tr){
                        return 0;
                } else if(l == tl && r == tr){
                        return t[x];
                }
                push(x);
                int m = (l + r) / 2;
                return max(get(x * 2, tl, min(m, tr), l, m),
                           get(x * 2 + 1, max(m + 1, tl), tr, m + 1, r));
        }
};

seg T[N];
int n;
int q;
long long W;
int a[N];
int b[N];
long long c[N];
vector < int > v[N];

bool dead[N];
int sz[N];

void dfs_s(int x, int p)
{
        sz[x] = 1;
        for(int i: v[x]){
                int y = a[i] ^ b[i] ^ x;
                if(dead[y] || y == p){
                        continue;
                }
                dfs_s(y, x);
                sz[x] += sz[y];
        }
}

int dfs_r(int x, int p, int S)
{
        int mx = S - sz[x];
        for(int i: v[x]){
                int y = a[i] ^ b[i] ^ x;
                if(dead[y] || y == p){
                        continue;
                }
                int g = dfs_r(y, x, S);
                if(g != -1){
                        return g;
                }
                mx = max(mx, sz[y]);
        }
        if(mx <= S / 2){
                return x;
        }
        return -1;
}

int G;
int tim;
int par[N];
int tin[N];
int tout[N];
vector < int > ch;

void dfs(int x, int p)
{
        ch.push_back(x);
        tin[x] = ++tim;
        for(int i: v[x]){
                int y = a[i] ^ b[i] ^ x;
                if(dead[y] || y == p){
                        continue;
                }
                par[y] = i;
                dfs(y, x);
        }
        tout[x] = tim;
}

vector < pair < pair < int, int >, int > > e[N];
vector < pair < int, int > > O[N];
vector < long long > best_o[N];
set < pair < long long, int > > s_o[N];
set < pair < long long, int > > all;

void ddd(int C, int g)
{
        long long L = 0;
        auto t = --s_o[C].end();
        L += t->first;
        if(s_o[C].size() > 1){
                t--;
                L += t->first;
        }
        if(g){
                all.insert({L, C});
        } else{
                all.erase({L, C});
        }
}

void build(int x)
{
        dfs_s(x, x);
        int S = sz[x];
        if(S == 1) return;
        x = dfs_r(x, x, S);
        G += 1;
        T[G].init(S);
        ch.clear();
        par[x] = tim = 0;
        dfs(x, x);
        for(int y: ch){
                if(par[y]){
                        e[par[y]].push_back({{tin[y], tout[y]}, G});
                        T[G].upd(1, tin[y], tout[y], c[par[y]], 1, S);
                }
        }
        for(int i: v[x]){
                int y = a[i] ^ b[i] ^ x;
                if(dead[y]){
                        continue;
                }
                O[G].push_back({tin[y], tout[y]});
                best_o[G].push_back(T[G].get(1, tin[y], tout[y], 1, S));
                s_o[G].insert({best_o[G].back(), best_o[G].size() - 1});
        }
        ddd(G, 1);
        dead[x] = true;
        for(int i: v[x]){
                int y = a[i] ^ b[i] ^ x;
                if(dead[y]){
                        continue;
                }
                build(y);
        }
}

void upd(int G, int in, int out, long long y)
{
        int l = 0, r = O[G].size() - 1;
        while(l < r){
                int m = (l + r) / 2;
                if(O[G][m].se < in){
                        l = m + 1;
                } else{
                        r = m;
                }
        }
        assert(O[G][l].fi <= in && O[G][l].se >= in);
        ddd(G, 0);
        s_o[G].erase({best_o[G][l], l});
        T[G].upd(1, in, out, y, 1, T[G].n);
        best_o[G][l] = T[G].get(1, O[G][l].fi, O[G][l].se, 1, T[G].n);
        s_o[G].insert({best_o[G][l], l});
        ddd(G, 1);
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> q >> W;
        for(int i = 1; i < n; i++){
                cin >> a[i] >> b[i] >> c[i];
                v[a[i]].push_back(i);
                v[b[i]].push_back(i);
        }
        build(1);
        long long res = 0;
        for(int i = 1; i <= q; i++){
                long long x;
                long long y;
                cin >> x >> y;
                x = (x + res) % (n - 1) + 1;
                y = (y + res) % W;
                for(auto p: e[x]){
                        upd(p.se, p.fi.fi, p.fi.se, y - c[x]);
                }
                c[x] = y;
                res = (--all.end())->first;
                cout << res << "\n";
        }
}