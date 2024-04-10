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

const int N = 3e5+7;
 
int a[N];
int l[N], r[N], nxt[N], par[N];
ii ed[N], d[N];
bool del[N];
ii seg[N]; //corner vertices
 
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

vi g[N];
map <ii, int> val;
namespace Tree {
int ptr = 0, h[N], l[N], r[N], jump[N], par[N], parE[N], maxOnJump[N];
void calc(int u, int p) {
    par[u] = p;
    if (u == p) {
        jump[u] = u;
        parE[u] = maxOnJump[u] = -1;
    }
    else if (h[p] - h[jump[p]] == h[jump[p]] - h[jump[jump[p]]]) {
        jump[u] = jump[jump[p]];
        parE[u] = maxOnJump[u] = val[mp(u, p)];
        ckmax(maxOnJump[u], maxOnJump[p]);
        ckmax(maxOnJump[u], maxOnJump[jump[p]]);
    }
    else {
        jump[u] = p;
        parE[u] = maxOnJump[u] = val[mp(u, p)];
    }
    l[u] = ptr;
    ptr++;    
    for (int v : g[u])  
        if (v != p) {
            h[v] = h[u]+1;
            calc(v, u);
        }
   r[u] = ptr - 1;
}   
bool anc(int u, int v) { return l[u] <= l[v] && r[v] <= r[u]; }
int lca(int u, int v) {
    if (anc(u,v))   
        return u;
    while (!anc(par[u], v)) {
        if (!anc(jump[u], v)) {
            u = jump[u];
        }
        else {
            u = par[u];
        }
    }
    return par[u];
}   
int dist(int u, int v) { return h[u] + h[v] - 2 * h[lca(u,v)]; }
int getm(int u, int p) {
    if (u == p) {
        return -1;
    }
    int ans = -1;
    while (u != p) {
        if (h[p] <= h[jump[u]]) {
            ckmax(ans, maxOnJump[u]);
            u = jump[u];
        }
        else {
            ckmax(ans, parE[u]);
            u = par[u];
        }
    }
    return ans;
}
int getmax(int u, int v) {
    int l = lca(u, v);
    return max(getm(u, l), getm(v, l));
}
}



signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n, q;
    cin >> n >> q;
    V <array <int, 3> > s;
    FOR (i, n - 1) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].app(v);
        g[v].app(u);
        s.app({c, u, v});
        val[mp(u,v)] = val[mp(v, u)] = c;
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
 
    debug(ord);

    for (int i = 0; i < n; ++i)
        pos[ord[i]] = i;

    FOR (i, N << 2) {
        tmin[i] = N;
        tmax[i] = -1;
    }
    build(0, 1, n);

    rep (q) {
        int t;
        cin >> t;
        if (t < 3) {
            int l, r;
            cin >> l >> r;
            turn(0, 1, n, l, r, t == 1);
        }
        else {
            int x;
            cin >> x;

            int L = tmin[0], R = tmax[0];
            int ans = -1;
            if (L != N) {
                ckmax(ans, Tree::getmax(x, ord[L]));
            }
            if (R != -1) {
                ckmax(ans, Tree::getmax(x, ord[R]));
            }
            cout << ans << endl;
        }
    }
}