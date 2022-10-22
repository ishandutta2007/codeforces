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
const int N = 3e5+7;
int n, m;
vi g[N];
bool used[N];
int par[N], h[N];
int sum[N];
vi tree[N];
void dfs(int u) {
    used[u] = 1;
    each (v, g[u]) {
        if (!used[v]) {
            h[v] = h[u] + 1;
            par[v] = u;
            dfs(v);
            tree[u].app(v);
        }
    }
}
int lca(int u, int v) {
    while (h[u] > h[v]) u = par[u];
    while (h[v] > h[u]) v = par[v];
    while (u != v) { u = par[u]; v = par[v]; }
    return u;
}
int ans = 0;
void solve(int u) {
    int t = 0;
    each (v, tree[u]) {
        solve(v);
        t += sum[v];
    }
    ans += t/2;
    t &= 1;
    if (t && sum[u] == 0) {
        ans++;
    }
}
signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m;
    rep (m) {
        int u, v;
        cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }
    dfs(1);
    V <ii> mem;
    int q; cin >> q;
    rep (q) {
        int u, v;
        cin >> u >> v;
        mem.app(mp(u, v));
        int l = lca(u, v);
        while (u != l) {
            sum[u] ^= 1;
            u = par[u];
        }
        while (v != l) {
            sum[v] ^= 1;
            v = par[v];
        }
    }
    bool ok = 1;
    FORN (u, n) {
        ok &= sum[u]%2==0;
    }
    if (ok) {
        cout << "YES" << endl;
        each (e, mem) {
            int u = e.x, v = e.y;
            int l = lca(u, v);
            vi le;
            while (u != l) {
                le.app(u);
                u = par[u];
            }

            vi ri;
            while (v != l) {
                ri.app(v);
                v = par[v];
            }
            reverse(all(ri));

            vi tot;
            each (e, le) tot.app(e); 
            tot.app(l);
            each (e, ri) tot.app(e);

            cout << tot.size() << endl << tot << endl;
        }
    }
    else {
        cout << "NO" << endl;
        solve(1);
        cout << ans << endl;
    }
}