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
vi g[N], gr[N];

vector<char> used;
vector<int> order, component;
 
void dfs1 (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i)
        if (!used[ g[v][i] ])
            dfs1 (g[v][i]);
    order.push_back (v);
}

void dfs2 (int v) {
    used[v] = true;
    component.push_back (v);
    for (size_t i=0; i<gr[v].size(); ++i)
        if (!used[ gr[v][i] ])
            dfs2 (gr[v][i]);
}

bool vis[N];
int h[N];
int comp[N];
int tot[N];

V <ii> G[N];
void dfs(int u) {
    vis[u] = 1;
    trav (e, G[u]) {
        int v = e.x, cost = e.y;
        if (!vis[v]) {
            h[v] = h[u] + cost;
            dfs(v);
        }
    }
}

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m;
    V <vi> me;
    FOR (i, m) {
        int u, v, l;
        cin >> u >> v >> l;
        g[u].app(v);
        gr[v].app(u);
        me.app({u, v, l});
    }
    used.assign (n + 1, false);
    for (int i=1; i<=n; ++i) {
        if (!used[i])
            dfs1 (i);
    }
    used.assign (n + 1, false);
    int cmp = 1;
    for (int i=0; i<n; ++i) {
        int v = order[n-1-i];
        if (!used[v]) {
            dfs2 (v);
            trav (e, component) {
                comp[e] = cmp;
            }
            cmp++;
            component.clear();
        }
    }

    trav (e, me) {
        int u = e[0], v = e[1], c = e[2];
        if (comp[u] == comp[v]) {
            G[u].app(mp(v, c));
        }
    }
    FORN (i, n) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    trav (e, me) {
        int u = e[0], v = e[1], c = e[2];
        if (comp[u] == comp[v]) {
            tot[comp[u]] = gcd(tot[comp[u]], abs(h[u] + c - h[v]));
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int u, s, t;
        cin >> u >> s >> t;
        int step = gcd(tot[comp[u]], t);
        if (s % step == 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}