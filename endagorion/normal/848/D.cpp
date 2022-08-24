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

const int maxn = 110;
const i64 P = 1000000000 + 7;
i64 ts[maxn][maxn], fs[maxn][maxn];
i64 fact[maxn], tcaf[maxn];

void add(i64 &x, i64 y) {
    x += y; x %= P;
}

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

i64 CNKr(i64 x, int k) {
    i64 y = tcaf[k];
    forn(i, k) (y *= x + i) %= P;
    return y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    fact[0] = 1;
    for1(i, maxn - 1) fact[i] = i * fact[i - 1] % P;
    forn(i, maxn) tcaf[i] = deg(fact[i], -1);

    int n, m;
    cin >> n >> m;

    fs[0][1] = 1;

    forn(i, n + 1) forn(j, n + 1) {
//        if (!T) continue;
        i64 T = ts[i][j];
        if (T) ford(ii, n + 1) ford(jj, n + 1) {
            if (!fs[ii][jj]) continue;
            for (int k = 1; ; ++k) {
                int ni = ii + k * i;
                int nj = jj + k * j;
                if (ni > n) break;
                add(fs[ni][nj], fs[ii][jj] * CNKr(T, k));
            }
        }

//        add(fs[i][j], T);
        forn(ii, i + 1) forn(jj, n + 1) {
            bool fin = ii == i && jj == j;
            add(ts[i + ii + 1][min(j, jj)], fs[i][j] * fs[ii][jj] * (fin ? 1 : 2));
            if (fin) break;
        }
//        add(fs[i][j], P - T);

//        cerr << i << ' ' << j << ' ' << fs[i][j] << ' ' << ts[i][j] << '\n';
    }

    cout << fs[n][m] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}