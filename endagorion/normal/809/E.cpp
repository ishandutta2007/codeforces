#include <bits/stdc++.h>

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

const int maxn = 210000;
const i64 P = 1000000000 + 7;

i64 deg(i64 x, i64 d) {
    d %= P - 1;
    if (d < 0) d += P - 1;
    i64 y = 1;
    while (d) {
        if (d & 1) (y *= x) %= P;
        d /= 2;
        (x *= x) %= P;
    }
    return y;
}

int mind[maxn], rad[maxn], phi[maxn];
int a[maxn], cnt[maxn];
i64 sphi[maxn];
vi pd[maxn];
vi ps;

i64 shalf[2][maxn];
int lacc[2][maxn];
i64 sp;

int T = 1;

void reset() {
    sp = 0;
    ++T;
}

i64 &get_sh(int z, int i) {
    if (lacc[z][i] < T) {
        lacc[z][i] = T;
        shalf[z][i] = (z ? 0LL : sphi[i]);
    }
    return shalf[z][i];
}

void rec(int z, int n, int pp, int delta, int i) {
    (get_sh(z, pp) += delta * phi[n]) %= P;
    (sp += delta * get_sh(z ^ 1, pp) * phi[n] / phi[pp]) %= P;
    for (; i < pd[n].size(); ++i) rec(z, n, pp * pd[n][i], delta, i + 1);
}

void change(int z, int i, int delta) {
    rec(z, i, 1, delta, 0);
}

void flip(int i, int from, int to) {
//    cerr << "F " << i << ' ' << from << ' ' << to << '\n';
    change(from, i, -1);
    change(to, i, 1);
}

int w[maxn];
vi e[maxn];

void dfsw(int v, int p) {
    w[v] = 1;
    for (int u: e[v]) {
        if (u == p) continue;
        dfsw(u, v);
        w[v] += w[u];
    }
    if (p != -1) e[v].erase(find(all(e[v]), p));
    sort(all(e[v]), [&](int a, int b){return w[a] > w[b];});
}

i64 ans = 0;
int n;

template<class T>
void dfs_perf(int v, const T &f) {
//    cerr << "P " << v << '\n';
    f(v);
    for (int u: e[v]) dfs_perf(u, f);
}

void dfs(int v) {
/*    cerr << v << ' ' << sp << '\n';
    forn(z, 2) for1(i, n) {
        cerr << z << ' ' << i << ' ' << get_sh(z, i) << '\n';
    }*/
    (ans += sp) %= P;
    if (e[v].empty()) return;
    flip(a[v], 1, 0);
    auto fflip = [&](int v) {
        flip(a[v], 1, 0);
    };
    for1(i, e[v].size() - 1) dfs_perf(e[v][i], fflip);
    dfs(e[v][0]);
    auto fflip2 = [&](int v) {
        flip(a[v], 0, 1);
    };
    for1(i, e[v].size() - 1) {
        reset();
        dfs_perf(e[v][i], fflip2);
        dfs(e[v][i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    forn(i, maxn) mind[i] = i;
    phi[1] = 1;
    fore(i, 2, maxn - 1) {
        if (i == mind[i]) ps.pb(i);
        phi[i] = (mind[i] - 1) * phi[i / mind[i]];
        if (mind[i] == mind[i / mind[i]]) phi[i] += phi[i / mind[i]];
        rad[i] = rad[i / mind[i]] * (mind[i] == mind[i / mind[i]] ? 1 : mind[i]);
        pd[i] = pd[i / mind[i]];
        if (mind[i] != mind[i / mind[i]]) pd[i].pb(mind[i]);
        for (int p: ps) {
            if (p > mind[i] || p * i >= maxn) break;
            mind[i * p] = p;
        }
    }

    cin >> n;

    forn(i, n) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    for1(i, maxn - 1) for1(j, (maxn - 1) / i) (sphi[i] += cnt[i * j] * phi[i * j]) %= P;

    forn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].pb(v);
        e[v].pb(u);
    }
    reset();
    forn(i, n) flip(a[i], 0, 1);
    dfsw(0, -1);
    dfs(0);
    
    (ans *= deg(1LL * n * (n - 1) / 2 % P, -1)) %= P;
    if (ans < 0) ans += P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}