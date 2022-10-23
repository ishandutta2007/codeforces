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
int dp[2][2][maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    forn(x, maxn) forn(y, maxn) forn(p, 2) forn(s, 2) {
        int &v = dp[p][s][x][y];
        if (!(x + y)) {
            v = p == s;
            continue;
        }
        v = 0;
        if (x) {
            int ns = s ^ p ^ 1;
            if (!dp[p ^ 1][ns][x - 1][y]) v = 1;
        }
        if (y) {
            if (!dp[p ^ 1][s][x][y - 1]) v = 1;
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi v(2);
        forn(i, n) {
            int x;
            cin >> x;
            ++v[x % 2 ? 1 : 0];
        }
        cout << (dp[0][0][v[1]][v[0]] ? "Alice" : "Bob") << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}