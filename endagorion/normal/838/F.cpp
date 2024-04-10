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
typedef long double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 11000;
ld dp[2][maxn], p[2][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(15);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    ld x;
    cin >> n >> x;
    x *= (ld)1e-6;
    forn(i, n + 1) {
        cin >> p[n & 1][i];
        p[n & 1][i] *= (ld)1e-6;
    }

    ford(s, n) {
        int i = s & 1, ii = i ^ 1;
        forn(r, s + 1) {
            ld pr = p[ii][r + 1] / (s + 1) * (r + 1), pb = p[ii][r] / (s + 1) * (s + 1 - r);
            p[i][r] = pr + pb;
            if (pr + pb > 0.0) dp[i][r] = max((ld)0.0, -x + (pr * (dp[ii][r + 1] + 1.0) + pb * dp[ii][r]) / (pr + pb));
//            cerr << s << ' ' << r << ' ' << pr << ' ' << pb << ' ' << p[i][r] << ' ' << dp[i][r] << '\n';
        }
    }

    cout << dp[0][0] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}