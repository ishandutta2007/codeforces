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

const i64 P = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    string s;
    cin >> s;

    vi64 dp(64);
    dp[0] = 1;
    for (char c: s) {
        vi64 ndp(64);
        int b = c - '0';
        forn(st, 64) if (dp[st]) {
//            cerr << c << ' ' << bitset<6>(st) << ' ' << dp[st] << '\n';
            forn(m, 8) {
                bool ok = true;
                forn(i, 3) if (!((st >> i) & 1) && ((m >> i) & 1) > b) ok = false;
                if (!ok) continue;
                int nst = st;
                forn(i, 3) if (((m >> i) & 1) < b) nst |= 1 << i;
                int x = m & 1, y = (m >> 1) & 1, z = (m >> 2) & 1;
                int a = x ^ y, b = x ^ z, c = y ^ z;
                if (a + b > c) nst |= 1 << 3;
                if (a + c > b) nst |= 1 << 4;
                if (b + c > a) nst |= 1 << 5;
//                cerr << m << ' ' << a << ' ' << b << ' ' << c << ' ' << bitset<6>(nst) << '\n';
                (ndp[nst] += dp[st]) %= P;
            }
        }
        dp = ndp;
    }

    i64 ans = 0;
    forn(i, 8) (ans += dp[56 + i]) %= P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}