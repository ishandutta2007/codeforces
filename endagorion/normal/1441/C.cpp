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

const int maxn = 3100, LOG = 15;
vi64 a[maxn];
i64 s[maxn];
i64 dp[LOG][maxn];

int n, k;

i64 ans = 0;

void dnc(int L, int R, int z) {
    if (R - L == 1) {
        i64 pr = 0;
        int ub = min((int)a[L].size(), k);
        forn(i, ub + 1) {
            uax(ans, pr + dp[z][k - i]);
            if (i < ub) pr += a[L][i];
        }
        return;
    }
    int M = (L + R) / 2;
    {
        forn(i, k + 1) dp[z + 1][i] = dp[z][i];
        fore(i, L, M - 1) {
            int sz = a[i].size();
            ford(j, k - sz + 1) uax(dp[z + 1][j + sz], dp[z + 1][j] + s[i]);
        }
        dnc(M, R, z + 1);
    }
    {
        forn(i, k + 1) dp[z + 1][i] = dp[z][i];
        fore(i, M, R - 1) {
            int sz = a[i].size();
            ford(j, k - sz + 1) uax(dp[z + 1][j + sz], dp[z + 1][j] + s[i]);
        }
        dnc(L, M, z + 1);
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

    cin >> n >> k;
    forn(i, n) {
        int l;
        cin >> l;
        a[i].resize(l);
        for (i64 &x: a[i]) cin >> x, s[i] += x;
    }

    forn(i, k + 1) dp[0][i] = -1e18;
    dp[0][0] = 0;
    dnc(0, n, 0);
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}