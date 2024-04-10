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
        int n;
        string s;
        cin >> n >> s;
        string ans = "-";
        vi cnt(10);
        for (char c: s) ++cnt[c - '0'];
        forn(d, 10) {
            string cols(n, '.');
            int pi = -1;
            bool ok = true;
            int smc = 0;
            forn(dd, d) smc += cnt[dd];
            forn(i, n) {
                if (s[i] > '0' + d) continue;
                if (s[i] < '0' + d) {
                    ok &= s[i] >= pi + '0';
                    pi = s[i] - '0';
                    cols[i] = '1';
                    --smc;
                } else {
                    if (!smc) cols[i] = '1';
                }
            }
            int lc = 0;
            fore(dd, d + 1, 9) lc += cnt[dd];
            pi = 10;
            ford(i, n) {
                if (cols[i] != '.') continue;
                if (s[i] < '0' + d) continue;
                if (s[i] > '0' + d) {
                    ok &= s[i] <= pi + '0';
                    pi = s[i] - '0';
                    cols[i] = '2';
                    --lc;
                } else {
                    if (!lc) cols[i] = '2';
                }
            }
            ok &= count(all(cols), '.') == 0;
            if (ok) {
                ans = cols;
                break;
            }
        }
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}