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

const int maxn = 12, maxm = 2100;
int best[1 << maxn];
int a[maxm][maxn];
int vals[1 << maxn];
int ctz[1 << maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        forn(i, 1 << n) best[i] = -1e9;
        best[0] = 0;
        for1(i, (1 << n) - 1) ctz[i] = __builtin_ctz(i);
        vi allnums;
        forn(i, n) forn(j, m) cin >> a[j][i];
        vi mx(m);
        forn(i, m) mx[i] = *max_element(a[i], a[i] + n);
        vi ord(m);
        iota(all(ord), 0);
        sort(all(ord), [&](int i, int j){return mx[i] > mx[j];});
        forn(i, m) {
            if (i > n + 1) break;
            int ci = ord[i];
            forn(k, 1 << n) vals[k] = 0;
            for1(k, (1 << n) - 1) {
                int z = ctz[k];
                int nk = k ^ (1 << z);
                vals[k] = vals[nk] + a[ci][z];
            }
            forn(j, n) forn(k, 1 << n) {
                int nk = (k >> 1) | ((k & 1) << (n - 1));
                uax(vals[k], vals[nk]);
            }
            ford(mask, 1 << n) {
                int rem = ((1 << n) - 1) ^ mask;
                for (int lft = rem; lft; --lft, lft &= rem) uax(best[mask | lft], best[mask] + vals[lft]);
            }
        }
        cout << best[(1 << n) - 1] << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}