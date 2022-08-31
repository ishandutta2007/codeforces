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
string s;
int nxt[maxn][26];

const int maxl = 271;
int dp[maxl][maxl][maxl];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, q;
    cin >> n >> q;
    cin >> s;
    s = '#' + s;
    ++n;
    forn(j, 26) nxt[n - 1][j] = nxt[n][j] = n;
    ford(i, n - 1) forn(j, 26) nxt[i][j] = s[i + 1] == (char)('a' + j) ? i + 1 : nxt[i + 1][j];

    vector<string> t(3);
    forn(i, q) {
        char c;
        cin >> c;
        if (c == '+') {
            int z;
            char l;
            cin >> z >> l;
            --z;
            if (z == 0) {
                t[0] += l;
                int i = t[0].size();
                forn(j, t[1].size() + 1) forn(k, t[2].size() + 1) dp[i][j][k] = nxt[dp[i - 1][j][k]][l - 'a'];
                forn(j, t[1].size() + 1) forn(k, t[2].size() + 1) {
                    if (j < t[1].size()) uin(dp[i][j + 1][k], nxt[dp[i][j][k]][t[1][j] - 'a']);
                    if (k < t[2].size()) uin(dp[i][j][k + 1], nxt[dp[i][j][k]][t[2][k] - 'a']);
                }
            } else if (z == 1) {
                t[1] += l;
                int j = t[1].size();
                forn(i, t[0].size() + 1) forn(k, t[2].size() + 1) dp[i][j][k] = nxt[dp[i][j - 1][k]][l - 'a'];
                forn(i, t[0].size() + 1) forn(k, t[2].size() + 1) {
                    if (i < t[0].size()) uin(dp[i + 1][j][k], nxt[dp[i][j][k]][t[0][i] - 'a']);
                    if (k < t[2].size()) uin(dp[i][j][k + 1], nxt[dp[i][j][k]][t[2][k] - 'a']);
                }
            } else {
                t[2] += l;
                int k = t[2].size();
                forn(i, t[0].size() + 1) forn(j, t[1].size() + 1) dp[i][j][k] = nxt[dp[i][j][k - 1]][l - 'a'];
                forn(i, t[0].size() + 1) forn(j, t[1].size() + 1) {
                    if (i < t[0].size()) uin(dp[i + 1][j][k], nxt[dp[i][j][k]][t[0][i] - 'a']);
                    if (j < t[1].size()) uin(dp[i][j + 1][k], nxt[dp[i][j][k]][t[1][j] - 'a']);
                }
            }
        } else {
            int z;
            cin >> z;
            --z;
            t[z].resize(t[z].size() - 1);
        }
        cout << (dp[t[0].size()][t[1].size()][t[2].size()] < n ? "YES" : "NO") << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}