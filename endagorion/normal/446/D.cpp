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

const int maxn = 510;
vi e[maxn];
int trap[maxn];

ld tr[maxn][maxn], inv[maxn][maxn];

using Matrix = vector<vector<ld> >;

Matrix operator*(const Matrix &a, const Matrix &b) {
    int n = a.size();
    Matrix c(n, vector<ld>(n));
    forn(i, n) forn(j, n) forn(k, n) c[i][k] += a[i][j] * b[j][k];
    return c;
}

Matrix deg(Matrix a, i64 d) {
    int n = a.size();
    Matrix c(n, vector<ld>(n));
    forn(i, n) c[i][i] = 1.0;
    while (d) {
        if (d & 1) c = c * a;
        a = a * a;
        d /= 2;
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m, k;
    cin >> n >> m >> k;

    vi traps;
    forn(i, n) {
        cin >> trap[i];
        if (trap[i]) traps.pb(i);
    }
    int T = traps.size();
    forn(i, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].pb(v);
        e[v].pb(u);
    }

    forn(v, n) {
        tr[v][v] = 1;
        if (trap[v]) continue;
        for (int u: e[v]) tr[v][u] -= 1.0 / e[v].size();
    }

    forn(v, n) inv[v][v] = 1.0;

    forn(j, n) {
        int bi = j;
        fore(i, j, n - 1) if (fabs(tr[i][j]) > fabs(tr[bi][j])) bi = i;
        forn(jj, n) {
            swap(tr[j][jj], tr[bi][jj]);
            swap(inv[j][jj], inv[bi][jj]);
        }
        ld z = tr[j][j];
        forn(jj, n) {
            tr[j][jj] /= z;
            inv[j][jj] /= z;
        }
        forn(i, n) {
            if (i == j) continue;
            ld z = tr[i][j];
            forn(jj, n) {
                tr[i][jj] -= z * tr[j][jj];
                inv[i][jj] -= z * inv[j][jj];
            }
        }
    }

    Matrix ttr(T, vector<ld>(T));
    vector<ld> init(T);
    forn(i, T) {
        int v = traps[i];
        init[i] = inv[0][v];
        for (int u: e[v]) {
            forn(j, T) ttr[i][j] += inv[u][traps[j]] / e[v].size();
        }
    }

    ttr = deg(ttr, k - 2);
    ld ans = 0.0;
    forn(i, T) ans += init[i] * ttr[i][T - 1];
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}