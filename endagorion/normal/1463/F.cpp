#include <bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

int dp[2][1 << 22];
int LIM = 200, C = 50;
int ans[10000 + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, x, y;
    cin >> n >> x >> y;
    if (x > y) swap(x, y);
    forn(mask, 1 << y) dp[0][mask] = -1e9;
    dp[0][0] = 0;

    int prv = 0, nxt = 1;
    forn(i, n + 1) {
        forn(mask, 1 << y) dp[nxt][mask] = -1e9;

        forn(mask, 1 << y) {
            uax(ans[i], dp[prv][mask]);
            forn(z, 2) {
                if (z) if (mask & (1 | (1 << (y - x)))) continue;
                uax(dp[nxt][(mask | (z << y)) >> 1], dp[prv][mask] + z);
            }
        }
//        cerr << i << ' ' << ans[i] << '\n';

        swap(prv, nxt);
        if (i >= LIM) {
            int ba = -1;
            for1(c, C) {                
                bool ok = true;
                int D = ans[i] - ans[i- c];
                forn(j, C) ok &= ans[i - j] - ans[i - j - c] == D;
                if (ok) {
                    int md = n % c;
                    while (md + c <= i) md += c;
                    uax(ba, ans[md] + (n - md) / c * D);
                }
            }
            if (ba != -1) {
               cout << ba << '\n';
               return 0;
            }
        }
    }

    cout << ans[n] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}