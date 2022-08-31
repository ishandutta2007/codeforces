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

const int maxn = 110000;
i64 cost[maxn];
i64 pc[maxn], sc[maxn];
i64 pcnt[2][maxn], scnt[2][maxn];

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
    int n = s.size();
    forn(z, 2) cin >> cost[z];

    i64 ans = 1e18;

    forn(z, 2) {
        forn(i, n) {
            int d = s[i] == '?' ? z : s[i] - '0';
            pc[i + 1] = pc[i] + cost[d ^ 1] * pcnt[d ^ 1][i];
            pcnt[d][i + 1] = pcnt[d][i] + 1;
            pcnt[d ^ 1][i + 1] = pcnt[d ^ 1][i];
        }
        forn(i, n) {
            int d = s[n - i - 1] == '?' ? z ^ 1 : s[n - i - 1] - '0';
            sc[i + 1] = sc[i] + cost[d] * scnt[d ^ 1][i];
            scnt[d][i + 1] = scnt[d][i] + 1;
            scnt[d ^ 1][i + 1] = scnt[d ^ 1][i];
        }

        forn(i, n + 1) {
            i64 res = pc[i] + sc[n - i];
            forn(y, 2) res += pcnt[y][i] * scnt[y ^ 1][n - i] * cost[y];
//            cerr << z << ' ' << i << ' ' << res << '\n';
            uin(ans, res);
        }
    }

    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}