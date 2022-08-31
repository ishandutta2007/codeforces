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
int t[maxn], x[maxn], y[maxn], ans[maxn], pans[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int r, n;
    cin >> r >> n;
    t[0] = 0;
    x[0] = y[0] = 1;
    ans[0] = pans[1] = 0;
    pans[0] = -1e9;
    for1(i, n) cin >> t[i] >> x[i] >> y[i];
    for1(i, n) {
        ans[i] = -1e9;
        int j = i - 1;
        while (j >= 0 && t[i] - t[j] <= 2 * r) {
            if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j]) uax(ans[i], ans[j] + 1);
            --j;
        }
        uax(ans[i], pans[j + 1] + 1);
//        cerr << i << ' ' << j << ' ' << ans[i] << '\n';
        pans[i + 1] = max(pans[i], ans[i]);
    }
    cout << max(0, pans[n + 1]) << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}