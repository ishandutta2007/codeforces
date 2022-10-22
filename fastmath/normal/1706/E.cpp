#pragma GCC optimize ("O3")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <fstream>
#include <array>
#include <functional>
#include <stack>
#include <memory>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define x first
#define y second
#define Time (double)clock()/CLOCKS_PER_SEC

#ifdef LOCAL
#define debug(x) std::cerr << #x << ": " << x << '\n';
#else
#define debug(x)
#endif

#define FORI(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR(i,a) FORI(i,0,a)
#define ROFI(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ROF(i,a) ROFI(i,0,a)
#define rep(a) FOR(_,a)
#define each(a,x) for (auto& a: x)
#define FORN(i, n) FORI(i, 1, n + 1)

using vi = vector<int>;
template <typename T>
std::istream& operator >>(std::istream& input, std::pair <T, T> & data)
{
    input >> data.x >> data.y;
    return input;
}
template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& data)
{
    for (T& x : data)
        input >> x;
    return input;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const pair <T, T> & data)
{
    output << "(" << data.x << "," << data.y << ")";
    return output;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& data)
{
    for (const T& x : data)
        output << x << " ";
    return output;
}
std::ostream& operator <<(std::ostream& output, const __int128 &x)
{
    __int128 n = x;
    if (n == 0) {
        output << "0";
        return output;
    }
    if (n < 0) {
        n = -n;
        output << "-";
    }
    string s;
    while (n) {
        s += '0' + (n%10);
        n /= 10;
    }
    reverse(all(s));
    cout << s;
    return output;
}
ll div_up(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll div_down(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down 
ll math_mod(ll a, ll b) { return a - b * div_down(a, b); }
#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>; 
tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; 
} // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; 
}
ll gcd(ll a, ll b) {
    while (b) {
        tie(a, b) = mp(b, a % b);
    }
    return a;
}
int Bit(int mask, int bit) { return (mask >> bit) & 1; }

const int LG = 20, N = 1e5+7;

/*
V <ii> g[N];
int ptr = 0, to[N][LG], h[N], l[N], r[N];
void calc(int u, int p) {
    to[u][0] = p;
    for (int i = 1; i < LG; ++i) {
        to[u][i] = to[to[u][i-1]][i-1];
    }
    l[u] = ptr;
    ptr++;    
    for (auto e : g[u]) {
        int v = e.x, c = e.y;
        if (v != p) {
            h[v] = h[u]+1;
            calc(v, u);
        }
    }
    r[u] = ptr - 1;
}   
bool anc(int u, int v) { return l[u] <= l[v] && r[v] <= r[u]; }
int lca(int u, int v) {
    if (u == -1) return v;
    if (v == -1) return u;
    if (anc(u,v))   
        return u;
    for (int i = LG - 1; i >= 0; --i)
        if (!anc(to[u][i], v))
            u = to[u][i];
    return to[u][0];
}   
int dist(int u, int v) { return h[u] + h[v] - 2 * h[lca(u,v)]; }
*/

struct Dsu {
int n;
vector <int> par, cnt;
Dsu (int n_) {
    n = n_;
    par.resize(n + 1);
    cnt.resize(n + 1, 1);
    FOR (i, n + 1)
        par[i] = i;
}   
int root(int u) {
    if (par[u] == u)
        return u;
    else
        return par[u] = root(par[u]);                
}   
int get_cnt(int u) {
    return cnt[root(u)];
}   
bool merge(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v)
        return 0;
    par[u] = v;
    cnt[v] += cnt[u];
    return 1;
}
bool connected(int u, int v) {
    return root(u) == root(v);
}   
bool cut(int u, int v) {
    return root(u) != root(v);
}
};  


//int a[N];
int l[N], r[N], nxt[N], par[N];
//ii ed[N], d[N];
//bool del[N];
//ii seg[N]; //corner vertices

int root(int u) {
    if (par[u] == u)
        return u;
    else
        return par[u] = root(par[u]);
}   
 
int mn[N << 2], mx[N << 2];
int pos[N];
 
void build(int v, int l, int r) {
    if (l == r) {
        mn[v] = mx[v] = pos[l];
        return;
    }
    int m = (l + r) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m + 1, r);
    mn[v] = min(mn[v * 2 + 1], mn[v * 2 + 2]);
    mx[v] = max(mx[v * 2 + 1], mx[v * 2 + 2]);
}
 
bool prop[N << 2], on[N << 2];
int tmin[N << 2], tmax[N << 2];
 
void gap(int v, bool t) {
    prop[v] = 1;
    on[v] = t;
    if (t) {
        tmin[v] = mn[v];
        tmax[v] = mx[v];
    }
    else {
        tmin[v] = N;
        tmax[v] = -1;
    }
}
void push(int v) {
    if (prop[v]) {
        gap(v * 2 + 1, on[v]);
        gap(v * 2 + 2, on[v]);
        prop[v] = 0;
    }
}
void relax(int v) {
    tmin[v] = min(tmin[v * 2 + 1], tmin[v * 2 + 2]);
    tmax[v] = max(tmax[v * 2 + 1], tmax[v * 2 + 2]);
}
void turn(int v, int l, int r, int ql, int qr, bool t) {
    if (r < ql || qr < l) {
        return;
    }
    if (ql <= l && r <= qr) {
        gap(v, t);
        return;
    }
    int m = (l + r) / 2;
    push(v);
    turn(v * 2 + 1, l, m, ql, qr, t);
    turn(v * 2 + 2, m + 1, r, ql, qr, t);
    relax(v);
}

int getmin(int v, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) {
        return N;
    }
    if (ql <= l && r <= qr) {
        return mn[v];
    }
    int m = (l + r) / 2;
    return min(getmin(v * 2 + 1, l, m, ql, qr), getmin(v * 2 + 2, m + 1, r, ql, qr));
}
int getmax(int v, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) {
        return -1;
    }
    if (ql <= l && r <= qr) {
        return mx[v];
    }
    int m = (l + r) / 2;
    return max(getmax(v * 2 + 1, l, m, ql, qr), getmax(v * 2 + 2, m + 1, r, ql, qr));
}
 
V <ii> g[N];
map <ii, int> val;
namespace Tree {
const int LG = 20;
int ptr = 0, to[N][LG], mx[N][LG], h[N], l[N], r[N], pare[N];
void calc(int u, int p) {
    to[u][0] = p;
    mx[u][0] = pare[u];
    for (int i = 1; i < LG; ++i) {
        to[u][i] = to[to[u][i-1]][i-1];
        mx[u][i] = max(mx[u][i - 1], mx[to[u][i-1]][i - 1]);
    }
    l[u] = ptr;
    ptr++;    
    for (auto e : g[u]) {
        int v = e.x, c = e.y;
        if (v != p) {
            h[v] = h[u]+1;
            pare[v] = c;
            calc(v, u);
        }
    }
    r[u] = ptr - 1;
}   
bool anc(int u, int v) { return l[u] <= l[v] && r[v] <= r[u]; }
int lca(int u, int v) {
    if (anc(u,v))   
        return u;
    for (int i = LG - 1; i >= 0; --i)
        if (!anc(to[u][i], v))
            u = to[u][i];
    return to[u][0];
}   
int dist(int u, int v) { return h[u] + h[v] - 2 * h[lca(u,v)]; }
int getm(int u, int p) {
    if (u == p) {
        return 0;
    }
    int ans = 0;
    for (int i = LG - 1; i >= 0; --i) {
        if (anc(p, to[u][i])) {
            ckmax(ans, mx[u][i]);
            u = to[u][i];
        }
    }
    return ans;
}
int getmax(int u, int v) {
    int l = lca(u, v);
    return max(getm(u, l), getm(v, l));
}
}


/*
int lc[N << 2];
void build(int v, int l, int r) {
    if (l == r) {
        lc[v] = l;
        return;
    }
    int m = (l + r) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m + 1, r);
    lc[v] = lca(lc[v * 2 + 1], lc[v * 2 + 2]);
}
int get(int v, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) {
        return -1;
    }
    if (ql <= l && r <= qr) {
        return lc[v];
    }
    int m = (l + r) / 2;
    return lca(get(v * 2 + 1, l, m, ql, qr), get(v * 2 + 2, m + 1, r, ql, qr));
}
*/

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    auto solve = [&] () {
        int n, m, q;
        cin >> n >> m >> q;
        FORN (u, n) {
            g[u].clear();
        }
        Tree::ptr = 0;

        V <array <int, 3> > s;

        Dsu d(n);
        FORN (c, m) {
            int u, v;
            cin >> u >> v;
            if (d.merge(u, v)) {
                g[u].app(mp(v, c));
                g[v].app(mp(u, c));
                s.app({c, u, v});
            }
        }

        Tree::calc(1, 1);
        for (int i = 1; i <= n; ++i) {
            l[i] = r[i] = i;
            nxt[i] = 0;
            par[i] = i;
        }   
        
        #define u first
        #define v second
     
        auto add = [&] (ii e) {
            int u = root(e.u);
            int v = root(e.v);
            if (u == v)
                return;
            par[u] = v;
            nxt[r[u]] = l[v];
            l[v] = l[u];
        };
     
        sort(all(s));
        for (int i = 0; i < n - 1; ++i) {
            add(mp(s[i][1], s[i][2]));
        }   
     
        vector <int> ord;
        vector <bool> in(n + 1);
        for (int i = 1; i <= n; ++i)
            if (nxt[i])
                in[nxt[i]] = 1;
     
        vector <int> si;
        for (int i = 1; i <= n; ++i)
            if (!in[i])
                si.app(i);
     
        for (int u : si) {
            while (u) {
                ord.app(u);
                u = nxt[u];
            }   
        }               
        assert(ord.size() == n);
     
        //debug(ord);
     
        for (int i = 0; i < n; ++i)
            pos[ord[i]] = i;
     
        FOR (i, n << 2) {
            tmin[i] = N;
            tmax[i] = -1;
        }
        build(0, 1, n);
     
        rep (q) {
            int l, r;
            cin >> l >> r;
            //debug(mp(l, r));
            int le = getmin(0, 1, n, l, r);
            int ri = getmax(0, 1, n, l, r);
            int u = ord[le], v = ord[ri];
            cout << Tree::getmax(u, v) << ' ';
        }
        cout << endl;

    };
    int t;
    cin >> t;
    rep (t) {
        solve();
    }
}