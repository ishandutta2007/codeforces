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

const int maxn = 4001;
vi e[2][maxn];
i64 dp[2][maxn][40];
vi64 cnt[2];

int k;

const i64 P = 998244353;

void add(i64 &x, i64 y) {
    x += y;
    if (x >= P) x -= P;
}

vi64 operator+(vi64 a, vi64 b) {
    assert(a.size() == k + 1);
    assert(b.size() == k + 1);

    forn(i, b.size()) add(a[i], b[i]);
    return a;
}

vi64 operator-(vi64 a, vi64 b) {
    assert(a.size() == k + 1);
    assert(b.size() == k + 1);

    forn(i, b.size()) add(a[i], P - b[i]);
    return a;
}


vi64 down[2][maxn];

vi64 combs(const vi64 &v) {
    vi64 res(k + 1);
    res[0] = 1;
    forn(i, k + 1) forn(j, k - i) add(res[i + j + 1], res[i] * v[j] % P);
    return res;
}

void dfs_down(int z, int v, int p) {
//    cerr << "D " << z << ' ' << v << '\n';
    vi64 sum(k + 1);
    for (int u: e[z][v]) {
        if (u == p) continue;
        dfs_down(z, u, v);
        sum = sum + down[z][u];
    }
    down[z][v] = combs(sum);
}

vi64 shift(vi64 a) {
    assert(a.size() == k + 1);
    a.insert(a.begin(), 0LL);
    a.pop_back();
    return a;
}

void dfs_up(int z, int v, int p, vi64 cup) {
/*    cerr << z << ' ' << v << ": ";
    for (i64 x: cup) cerr << x << ' ';
    cerr << '\n';*/
    vi64 total = cup;
    for (int u: e[z][v]) {
        if (u == p) continue;
        total = total + down[z][u];
    }
//    for (i64 x: total) cerr << x << ' ';
//    cerr << '\n';
    cnt[z] = cnt[z] + combs(total);
    for (int u: e[z][v]) {
        if (u == p) continue;
        auto ncup = total - down[z][u];
//        ncup = shift(ncup);
//        ++ncup[0];
        dfs_up(z, u, v, combs(ncup));
    }
}


i64 cnk[80][80];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n[2];
    forn(i, 2) cin >> n[i];
    cin >> k;
    if (k & 1) {
        cout << 0 << '\n';
        return 0;
    }
    k /= 2;
    cnk[0][0] = 1;
    forn(i, 2 * k) forn(j, i + 1) forn(z, 2) add(cnk[i + 1][j + z], cnk[i][j]);

    forn(i, 2) forn(j, n[i] - 1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[i][u].pb(v);
        e[i][v].pb(u);
    }

    forn(j, 2) {
        cnt[j] = vi64(k + 1);
        dfs_down(j, 0, -1);
        dfs_up(j, 0, -1, vi64(k + 1));
//        for (i64 x: cnt[j]) cerr << x << ' ';
//        cerr << '\n';
    }

    i64 ans = 0;
    forn(l1, k + 1) add(ans, cnt[0][l1] * cnt[1][k - l1] % P * cnk[2 * k][2 * l1] % P);

    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}