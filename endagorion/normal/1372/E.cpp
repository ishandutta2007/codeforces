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

const int maxn = 101;
int ins[maxn][maxn];
int dp[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m;
    cin >> n >> m;
    forn(i, n) {
        int k;
        cin >> k;
        while (k--) {
            int l, r;
            cin >> l >> r;
            --l;
            ++ins[l][r];
        }
    }

    forn(r, m + 1) ford(l, r) {
        ins[l][r] += ins[l + 1][r];
        ins[l][r] += ins[l][r - 1];
        ins[l][r] -= ins[l + 1][r - 1];
    }

    forn(r, m + 1) ford(l, r) {
        fore(i, l, r - 1) {
            int x = ins[l][r] - ins[l][i] - ins[i + 1][r];
            uax(dp[l][r], x * x + dp[l][i] + dp[i + 1][r]);
        }
    }

    cout << dp[0][m] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}