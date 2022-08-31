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

const int maxn = 100;
ld p[2][maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, k;
    cin >> n >> k;
    uin(k, 1000);
    vi a(n);
    forn(i, n) cin >> a[i];
    forn(i, n) forn(j, i) p[0][j][i] = int(a[j] > a[i]);

    int segs = n * (n + 1) / 2;

    forn(i, k) {
        auto cur = p[i & 1], nxt = p[(i & 1) ^ 1];
        forn(i, n) forn(j, i) {
            nxt[j][i] = cur[j][i] * segs;
            forn(to, i) {
                int mul = min(i - max(to, j), min(to, j) + 1);
//                    cerr << j << " -> " << to << ", " << i << " = " << mul << '\n';
                nxt[j][i] += mul * (cur[to][i] - cur[j][i]);
            }
            fore(to, j + 1, n - 1) {
                int mul = min(n - max(to, i), min(to, i) - j);
//                    cerr << j << ", " << i << " -> " << to << " = " << mul << '\n';
                nxt[j][i] += mul * (cur[j][to] - cur[j][i]);
            }
            forn(to, n - (i - j)) {
                int toi = to, toj = toi + i - j;
//                if (toj >= n) continue;
                int mul = min(min(j, toi) + 1, n - max(i, toj));
//                cerr << j << " -> " << toj << ", " << i << " -> " << toi << " = " << mul << '\n';
                nxt[j][i] += mul * (1.0 - cur[toi][toj] - cur[j][i]);
            }
            nxt[j][i] /= segs;
        }
    }

    double ans = 0.0;
    forn(i, n) forn(j, i) ans += p[k & 1][j][i];
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}