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

const int maxn = 3100;
const i64 P = 998244353;

i64 part[maxn][maxn];
i64 suf[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    forn(i, m - 1) if (t[i] == s[0]) part[i][i + 1] = 2;
    suf[1][t.size()] = 2;
    if (t.back() == s[0]) suf[1][t.size() - 1] = 2;
    i64 ans = 0;
    for1(i, n - 1) {
        (ans += suf[i][0]) %= P;
        forn(j, m - i) {
//            if (part[j][j + i]) cerr << j << ' ' << j + i << ' ' << part[j][j + i] << '\n';
            if (j && s[i] == t[j - 1]) (part[j - 1][j + i] += part[j][j + i]) %= P;
            if (j + i < m && s[i] == t[j + i]) {
                i64 &v = j + i + 1 == m ? suf[i + 1][j] : part[j][j + i + 1];
                (v += part[j][j + i]) %= P;
            }
        }
        forn(j, m + 1) {
            if (j && s[i] == t[j - 1]) (suf[i + 1][j - 1] += suf[i][j]) %= P;
            (suf[i + 1][j] += suf[i][j]) %= P;
        }
        (suf[i + 1][m] += suf[i][m]) %= P;
    }
    (ans += suf[n][0]) %= P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}