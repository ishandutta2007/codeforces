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

const int maxn = 110000, maxk = 201;
const i64 P = 1000000000 + 7;

vi e[maxn];
vi64 pol[maxn][2];
i64 ans[maxk];
i64 d2[maxn];

int n, k;

void add(i64 &x, i64 y) {
    (x += y) %= P;
}

vi64 operator+(const vi64 &a, const vi64 &b) {
    vi64 c(max(a.size(), b.size()));
    forn(i, c.size()) {
        if (i < a.size()) add(c[i], a[i]);
        if (i < b.size()) add(c[i], b[i]);
    }
    return c;
}

vi64 operator*(const vi64 &a, const vi64 &b) {
    assert(a.size() <= k + 1 && b.size() <= k + 1);
    if (a.empty() && b.empty()) return vi64();
    vi64 c(min(int(a.size() + b.size() - 1), k + 1));
    forn(i, a.size()) { 
        int z = min(int(b.size()), k + 1 - i);
        forn(j, z) add(c[i + j], a[i] * b[j]);
    }
//    if (c.size() > k + 1) c.resize(k + 1);
    return c;
}

vi64 b[2], c[2];
int w[maxn];

void dfs0(int v, int p) {
    w[v] = 1;
    for (int u: e[v]) {
        if (u == p) continue;
        dfs0(u, v);
        w[v] += w[u];
    }
}

void dfs(int v, int p) {
    pol[v][0] = {1};
    for (int u: e[v]) {
        if (u == p) continue;
        dfs(u, v);
        forn(i, 2) b[i].clear();
        forn(i, 2) forn(j, 2) {
            if (pol[u][i].empty()) continue;
            if (j) {
                vi64 z = pol[u][i] * vi64({0, 1});
//                b[1] = b[1] + pol[u][i] * vi64({0, 1});
                add(z[1], (P - d2[w[u]]) * pol[u][i][0]);
                forn(i, z.size()) add(ans[i], z[i] * (P + 1 - d2[n - w[u]]));
                b[1] = b[1] + z;
            }
            else b[i] = b[i] + pol[u][i];
        }


        forn(i, 2) c[i].clear();
        c[0] = (pol[v][0] + pol[v][1]) * (b[0] + b[1]);
        c[1] = pol[v][1] + b[1];
        c[0] = c[0] + c[1] * vi64({P - 1});
        forn(i, 2) pol[v][i] = c[i];
    }

/*    cerr << v << '\n';
    forn(i, 2) {
        for (int x: pol[v][i]) cerr << x << ' ';
        cerr << '\n';
    }
    forn(i, k + 1) cerr << ans[i] << ' ';
    cerr << '\n';
    cerr << "---\n";*/
}

i64 coef[maxk][maxk], cnk[maxk][maxk];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> k;
    forn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[v].pb(u);
        e[u].pb(v);
    }

    i64 i2 = (P + 1) / 2 % P;
    d2[0] = 1;
    for1(i, n) d2[i] = d2[i - 1] * i2 % P;

    dfs0(0, -1);
    dfs(0, -1);
    forn(i, pol[0][0].size()) add(ans[i], pol[0][0][i]);

    cnk[0][0] = 1;
    forn(i, k) forn(j, i + 1) forn(z, 2) add(cnk[i + 1][j + z], cnk[i][j]);

    coef[0][0] = 1;
    forn(i, k) forn(j, k) for1(z, k - j) add(coef[i + 1][j + z], coef[i][j] * cnk[j + z][z]);

    i64 total = 0;
    for1(i, k) add(total, ans[i] * coef[i][k]);
    forn(i, n) (total *= 2) %= P;
    cout << total << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}