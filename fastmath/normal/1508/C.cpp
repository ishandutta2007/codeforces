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
#define debug(x) std::cerr << #x << ": " << x << '\n';
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define FORN(i, n) for (int i = 1; i <= n; ++i)
#define pb push_back
#define trav(a, x) for (auto& a : x)
using vi = vector<int>;
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
ll div_up(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll div_down(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down 
ll math_mod(ll a, ll b) { return a - b * div_down(a, b); }
#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>; 
tcT> void re(V<T>& x) { 
    trav(a, x)
        cin >> a;
}
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

const int N = 2e5+7;
int n, m;

set <signed> nu;
set <pair <signed, signed> > ed;
V <V <signed> > E;

signed comp[N];
V <pair <signed, signed> > tree[N];
void dfs(int u, int c) {
    comp[u] = c;
    int prv = -1;
    while (1) {
        auto t = nu.upper_bound(prv);
        if (t == nu.end()) {
            break;
        }
        int v = *t;
        prv = v;
        if (ed.count(mp(u, v))) {
            continue;
        }
        nu.erase(t);

        tree[u].app(mp(v, 1));
        tree[v].app(mp(u, 1));

        dfs(v, c);
    }
}

struct Dsu {
int n;
vector <signed> par, cnt;
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
};  

const int INF = 2e18;

int ptr = 0, h[N], l[N], r[N], par[N], jump[N];
void calc(int u, int p) {
    par[u] = p;
    if (u == p) {
        jump[u] = u;
    }
    else if (h[p] - h[jump[p]] == h[jump[p]] - h[jump[jump[p]]]) {
        jump[u] = jump[jump[p]];
    }
    else {
        jump[u] = p;
    }
    l[u] = ptr;
    ptr++;    
    for (auto [v, c] : tree[u]) {
        if (v != p) {
            h[v] = h[u]+c;
            calc(v, u);
        }
    }
    r[u] = ptr - 1;
}   
bool anc(int u, int v) { return l[u] <= l[v] && r[v] <= r[u]; }
int lca(int u, int v) {
    if (anc(u, v)) { 
        return u;
    }
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

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m;

    int sum = 0;
    FOR (i, m) {
        signed u, v, c;
        cin >> u >> v >> c;
        E.app({c, u, v});
        ed.insert(mp(u, v));
        ed.insert(mp(v, u));
        sum ^= c;
    }

    FORN (u, n) {
        nu.insert(u);
    }

    int cmp = 1;
    FORN (u, n) {
        if (nu.count(u)) {
            nu.erase(u);
            dfs(u, cmp);
            cmp++;            
        }
    }

    sort(all(E));

    Dsu d(n);
    int scape = INF;
    int ans = 0;

    V <V <signed> > cand;
    FOR (i, m) {
        int u = E[i][1];
        int v = E[i][2];
        int c = E[i][0];
        if (comp[u] == comp[v]) {
            ckmin(scape, c);
        }
        else {
            int cu = comp[u], cv = comp[v];
            if (!d.connected(cu, cv)) {
                d.merge(cu, cv);
                tree[u].app(mp(v, 0)); tree[v].app(mp(u, 0));
                ans += c;
            }
            else {
                cand.app(E[i]);
            }
        }
    }

    calc(1, 1);
    trav (e, cand) {
        int u = e[1], v = e[2], c = e[0];
        if (dist(u, v)) {
            ckmin(scape, c);
        }
    }

    int tot = n * (n - 1) / 2;
    int anti = tot - m;

    int k = cmp - 1;

    if (anti != n - k) {
        cout << ans << endl;
    }
    else {
        cout << ans + min(scape, sum) << endl;
    }
}