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

const int P = 1000000000 + 7;

void add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}

int dp[8];
int buf[5];

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
        i64 m;
        cin >> m;
        forn(i, 8) dp[i] = 0;
        dp[0] = 1;
        while (m) {
//            vi64 ndp(8);
            forn(j, 5) buf[j] = 0;
            forn(i, 8) {
                int ni = ((i & 1) && !(m & 1) ? i / 2 + 1 : i / 2);
                add(buf[ni], dp[i]);
                dp[i] = 0;
            }
            int sum = 0;
            forn(i, 8) {
                if (i < 5) add(sum, buf[i]);
                if (i >= 4) add(sum, P - buf[i - 4]);
                dp[i] = sum;
            }
//            forn(i, 5) forn(j, 4) add(dp[i + j], buf[i]);
            m /= 2;
        }
        cout << dp[0] << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}