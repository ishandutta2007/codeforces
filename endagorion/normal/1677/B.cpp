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
        int n, m;
        string s;
        cin >> n >> m >> s;
        vi nxt(n * m, 1e9);
        ford(i, n * m) {
            if (s[i] == '1') nxt[i] = i;
            else if (i + m < n * m) nxt[i] = nxt[i + m];
        }
        vi gc(n * m), gr(n * m);
        forn(i, m) {
            if (nxt[i] < n * m) ++gr[nxt[i]];
        }
        vi ps(n * m + 1);
        forn(i, n * m) ps[i + 1] = ps[i] + s[i] - '0';

        forn(i, m) {
            for (int j = i + 1; j <= n * m; j += m) {
                if (ps[j] - ps[max(0, j - m)]) {
//                    cerr << max(0, j - m) << ' ' << j << '\n';
                    ++gc[j - 1];
                }
            }
        }
//        forn(i, n * m) cout << gc[i] << ' ';
//        cout << '\n';

        fore(i, m, n * m - 1) gc[i] += gc[i - m];
        for1(i, n * m - 1) gr[i] += gr[i - 1];

        forn(i, n * m) cout << gc[i] + gr[i] << ' ';
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}