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

const int N = 1e5+7;
V <ii> tree[N];

int ptr = 0, h[N], l[N], r[N], par[N], jump[N], pare[N];
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
            pare[v] = c;
            h[v] = h[u]+1;
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
int prv(int u, int p) {
    while (!anc(par[u], p)) {
        if (!anc(jump[u], p)) {
            u = jump[u];
        }
        else {
            u = par[u];
        }
    }   
    return u;
}
int dist(int u, int v) { return h[u] + h[v] - 2 * h[lca(u,v)]; }

int sub[N];
void dfs(int u, int p) {
    each (e, tree[u]) {
        int v = e.x, c = e.y;
        if (v != p) {
            sub[v] += sub[u];
            dfs(v, u);
        }
    }
}

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    Dsu d(n);
    V <array <int, 3> > b;
    rep (m) {
        int u, v;
        cin >> u >> v;
        if (d.merge(u, v)) {
            tree[u].app(mp(v, _));
            tree[v].app(mp(u, _));
        }
        else {
            b.app({u, v, _});
        }   
    }
    calc(1, 1);
    each (e, b) {
        int u, v, c;
        u = e[0], v = e[1], c = e[2];
        if (anc(v, u)) {
            swap(u, v);
        }
        sub[1]++;
        if (anc(u, v)) {
            int p = prv(v, u);
            if (pare[v] < c) {
                sub[v]--;
            }
            if (pare[p] < c) {
                sub[1]--;
                sub[p]++;
            }
        }
        else {
            if (pare[u] < c) {
                sub[u]--;
            }
            if (pare[v] < c) {
                sub[v]--;
            }
        }
    }
    dfs(1, 1);
    FORN (u, n) cout << (sub[u] == 0);
    cout << endl;
}