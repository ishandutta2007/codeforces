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
        vi n(3);
        forn(i, 3) cin >> n[i];
        vvi64 a(3);
        forn(i, 3) {
            a[i].resize(n[i]);
            forn(j, n[i]) cin >> a[i][j];
            sort(all(a[i]));
        }

        vi perm(3);
        iota(all(perm), 0);
        i64 ans = 4e18;
        do {
            int x = perm[0], y = perm[1], z = perm[2];
            int i = 0, j = 0, k = 0;
            while (j < a[y].size()) {
//                cerr << i << ' ' << j << ' ' << k << '\n';
                while (i + 1 < a[x].size() && a[x][i + 1] <= a[y][j]) ++i;
                while (k + 1 < a[z].size() && a[z][k] < a[y][j]) ++k;
                i64 A = a[x][i], B = a[y][j], C = a[z][k];
                uin(ans, (A - B) * (A - B) + (A - C) * (A - C) + (B - C) * (B - C));
                ++j;
            }
        } while (next_permutation(all(perm)));
        cout << ans << '\n';
    }
    

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}