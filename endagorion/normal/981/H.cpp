#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const i64 P = 998244353;
const int maxn = 1 << 18;

void add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}

i64 deg(i64 x, i64 d) {
    d %= P - 1;
    if (d < 0) d += P - 1;
    i64 y = 1;
    while (d) {
        if (d & 1) (y *= x) %= P;
        (x *= x) %= P;
        d /= 2;
    }
    return y;
}

int bitrev(int n, int i) {
    for (int l = 1, r = n / 2; l < r; l <<= 1, r >>= 1) {
        if (((i / l) & 1) != ((i / r) & 1)) i ^= l | r;
    }
    return i;
}

i64 omega = 0;
i64 r[20][2 * maxn];

void fft(int n, int *a, bool inv) {
    forn(i, n) {
        int j = bitrev(n, i);
        if (i < j) swap(a[i], a[j]);
    }
    for (int l = 1, q = 0; l < n; l *= 2, ++q) {
//        int w0 = deg(omega, maxn / l / 2);
//        if (inv) w0 = deg(w0, -1);
        for (int i = 0; i < n; i += 2 * l) {
//            int w = 1;
            forn(j, l) {
                int x = a[i + j], y = a[i + l + j];
                int z = 1LL * y * r[q][inv ? (2 << q) - j : j] % P;
                a[i + j] = (x + z) % P;
                a[i + l + j] = (x - z) % P;
//                w = 1LL * w * w0 % P;
            }
        }
    }
    if (inv) {
        int z = deg(n, -1);
        forn(i, n) a[i] = 1LL * a[i] * z % P;
    }
}

int pa[maxn], pb[maxn], res[maxn];

void sum(const vi &a, const vi &b, vi &c) {
    int n = max(a.size(), b.size());
    c.assign(n, 0);
    forn(i, n) {
        if (i < a.size()) add(c[i], a[i]);
        if (i < b.size()) add(c[i], b[i]);
    }
}

void prod(const vi &a, const vi &b, vi &c) {
    if (a.empty() || b.empty()) {
        c.clear();
        return;
    }
    int n = a.size(), m = b.size();
    c.assign(n + m - 1, 0);
    int N = 1;
    while (N < n + m) N *= 2;
    forn(i, N) pa[i] = i < n ? a[i] : 0;
    fft(N, pa, false);
    forn(i, N) pb[i] = i < m ? b[i] : 0;
    fft(N, pb, false);
    forn(i, N) pa[i] = 1LL * pa[i] * pb[i] % P;
    fft(N, pa, true);
    forn(i, n + m - 1) if ((c[i] = pa[i]) < 0) c[i] += P;
}

void dncprod(const vvi &muls, const vi &x, int l, int r, vi &s0, vi &s1) {
    if (l == r) {
        s0 = {1};
        s1 = {};
        return;
    }
    if (r - l == 1) {
        s0 = muls[l];
        s1 = {x[l]};
        return;
    }
    int m = (l + r) / 2;
    vi ls0, ls1, rs0, rs1;
    dncprod(muls, x, l, m, ls0, ls1);
    dncprod(muls, x, m, r, rs0, rs1);
    prod(ls0, rs0, s0);
    vi h1, h2;
    prod(ls0, rs1, h1);
    prod(ls1, rs0, h2);
    sum(h1, h2, s1);
}

vi dprod(const vi &a, const vi &b) {
    if (a.empty() || b.empty()) return {};
    vi c(a.size() + b.size() - 1);
    forn(i, a.size()) forn(j, b.size()) add(c[i + j], 1LL * a[i] * b[j] % P);
    return c;
}

int n, k;
vi e[maxn];
int down[maxn], sdown[maxn];
int w[maxn];

i64 fact[maxn], tcaf[maxn];
int total = 0;

void dfs(int v, int par) {
    vvi muls;
    vi x;
    w[v] = 1;
    i64 sd = 0;
    for (int u: e[v]) {
        if (u == par) continue;
        dfs(u, v);
        w[v] += w[u];
        muls.pb({1, w[u]});
        x.pb(sdown[u]);
        add(total, 1LL * sdown[v] * sdown[u] % P);
        add(sdown[v], sdown[u]);
    }
    vi p, q;
    dncprod(muls, x, 0, muls.size(), p, q);
    forn(i, p.size()) {
        if (i > k) break;
        add(down[v], 1LL * p[i] * fact[k] % P * tcaf[k - i] % P);
    }                
    add(sdown[v], down[v]);

    q = dprod(q, {1, n - w[v]});

    forn(i, q.size()) {
        if (i > k) break;
        add(total, 1LL * q[i] * fact[k] % P * tcaf[k - i] % P);
    }
//    cerr << v << ' ' << total << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    while (1) {
        if (deg(omega, maxn) == 1 && deg(omega, maxn / 2) != 1) break;
        ++omega;
    }

    forn(i, 17) {
        r[i][0] = 1;
        i64 w0 = deg(omega, maxn >> (i + 1));
        forn(j, 1 << (i + 1)) r[i][j + 1] = 1LL * r[i][j] * w0 % P;
    }

    cin >> n >> k;
    fact[0] = 1;
    for1(i, k) fact[i] = i * fact[i - 1] % P;
    forn(i, k + 1) tcaf[i] = deg(fact[i], -1);
    forn(i, n - 1) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        e[x].pb(y);
        e[y].pb(x);
    }
    if (k > 1) dfs(0, -1);
    else total = 1LL * n * (n - 1) / 2 % P;
    cout << total << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}