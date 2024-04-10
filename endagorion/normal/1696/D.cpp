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

const int maxn = 510000, LOG = 21;
int a[2][maxn];                          
int sp[2][LOG + 1][maxn];

int rmq(int z, int L, int R) {
    int j = 0;
    while ((2 << j) <= R - L) ++j;
    int x = sp[z][j][L], y = sp[z][j][R - (1 << j)];
    return a[z][x] < a[z][y] ? x : y;
}

int path(int L, int R) {
    if (L == R) return 0;
    int m1 = rmq(0, L, R + 1), m2 = rmq(1, L, R + 1);
    if (m1 > m2) swap(m1, m2);
    if (m1 == L && m2 == R) return 1;
    int ans = 0;
    if (L != m1) ans += path(L, m1);
    if (m1 != m2) ans += path(m1, m2);
    if (m2 != R) ans += path(m2, R);
    return ans;
}

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
        cin >> n;
        forn(i, n) cin >> a[0][i];
        forn(i, n) a[1][i] = -a[0][i];
        forn(z, 2) {
            forn(i, n) sp[z][0][i] = i;
            forn(j, LOG) forn(i, n) {
                sp[z][j + 1][i] = sp[z][j][i];
                int ii = i + (1 << j);
                if (ii < n && a[z][sp[z][j][ii]] < a[z][sp[z][j][i]]) sp[z][j + 1][i] = sp[z][j][ii];
            }
        }
        cout << path(0, n - 1) << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}