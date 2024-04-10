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

int fromHex(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    return 10 + c - 'a';
}

i64 dp[2][2][2];

i64 solve(string s, bool eq) {
//    reverse(all(s));
    int n = s.size();
    i64 ans = 0;
    forn(D, 16) {
        forn(x, 2) forn(y, 2) dp[0][x][y] = 0; // less, have D
        dp[0][0][0] = 1;
        ford(i, n) {
            char c = s[i];
            int cb = -1;
            if (D / 4 == i) cb = D % 4;
            int sd = fromHex(c);
            forn(x, 2) forn(y, 2) dp[1][x][y] = 0;
            forn(x, 2) forn(y, 2) forn(d, D + 1) {
                if (!x && d > sd) continue;
                if (cb != -1 && !((d >> cb) & 1)) continue;
                int nx = x ? 1 : int(d < sd);
                int ny = y | int(d == D);
                dp[1][nx][ny] += dp[0][x][y];
            }
            forn(x, 2) forn(y, 2) dp[0][x][y] = dp[1][x][y];
        }
        ans += dp[0][1][1];
        if (eq) ans += dp[0][0][1];
    }
    return ans;
}

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
        string L, R;
        cin >> L >> R;
        reverse(all(L)); L.resize(16, '0');
        reverse(all(R)); R.resize(16, '0');
        cout << solve(R, 1) - solve(L, 0) << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}