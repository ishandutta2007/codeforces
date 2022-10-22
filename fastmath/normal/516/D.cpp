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
const int N = 1e5+7;
int n;
V <ii> g[N];
int down[N], up[N], d[N];

void dfs1(int u, int p) {
    each (e, g[u]) {
        int v = e.x, c = e.y;
        if (v != p) {
            dfs1(v, u);
            ckmax(down[u], down[v] + c);
        }
    }
}
void dfs2(int u, int p) {
    vi d = {0};
    each (e, g[u]) {
        int v = e.x, c = e.y;
        if (v != p) {
            d.app(down[v] + c);
        }
    }
    sort(all(d));
    reverse(all(d));
    each (e, g[u]) {
        int v = e.x, c = e.y;
        if (v != p) {
            ckmax(up[v], up[u] + c);
            if (down[v] + c != d[0]) {
                ckmax(up[v], d[0] + c);
            }
            else {
                ckmax(up[v], d[1] + c);
            }
            dfs2(v, u);
        }
    }
}

int sz = 0;
int who[N], add[N];
void dfs3(int u, int p, int L) {
    who[sz] = u;
    sz++;

    int l = -1, r = sz;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (d[who[m]] < d[u] - L) {
            l = m;
        }
        else {
            r = m;
        }
    }

    if (l >= 0) {
        add[who[l]]--;
    }
    add[u]++;

    each (e, g[u]) {
        int v = e.x;
        if (v != p) {
            dfs3(v, u, L);    
        }
    }
    sz--;
}

void dfs4(int u, int p, int &ans) {
    each (e, g[u]) {
        int v = e.x;
        if (v != p) {
            dfs4(v, u, ans);
            add[u] += add[v];
        }
    }
    ckmax(ans, add[u]);
}

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    rep (n - 1) {
        int u, v, x;
        cin >> u >> v >> x;
        g[u].app(mp(v, x));
        g[v].app(mp(u, x));
    }
    dfs1(1, 1);
    dfs2(1, 1);
    int root = 1;
    FORN (i, n) {
        d[i] = max(up[i], down[i]);
        if (d[i] < d[root]) {
            root = i;
        }
    }
    int q;
    cin >> q;
    rep (q) {
        int l;
        cin >> l;
        memset(add, 0, sizeof add);
        dfs3(root, root, l);
        int ans = 0;
        dfs4(root, root, ans);
        cout << ans << endl;
    }
}