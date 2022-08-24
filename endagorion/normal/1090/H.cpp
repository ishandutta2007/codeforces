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

const int maxn = 200000, LOG = 20;
string s;
int pd[LOG + 1][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n >> s;
//    forn(i, n - 1) cerr << (s[i] ^ s[i + 1]);
//    cerr << '\n';
    forn(j, LOG) forn(i, n - 1) {
        pd[j][i] = s[i] ^ s[i + 1];
        if (i >= (1 << j)) pd[j][i] += pd[j][i - (1 << j)];
    }

    int q;
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        ++R;
        int k = 0;
        while ((2 << k) <= R - L) ++k;
        int total = 0;
        forn(j, k) {
            int res = pd[j + 1][R - 1 - (1 << j)];
            if (L > (1 << j)) res -= pd[j + 1][L - 1 - (1 << j)];
//            cerr << L << ' ' << R << ' ' << k << ' ' << j << ' ' << res << '\n';
//            cerr << L - 1 - (1 << j) << ' ' << R - 1 - (1 << j) << pd[j + 1][L - 1 - (1 << j)] << ' ' << (res = pd[j + 1][L - 1 - (1 << j)]) << '\n';
            total += min((1 << (k - j - 1)) - res, res);
        }
//        cerr << total << '\n';
        cout << (total + 1) / 2 << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}