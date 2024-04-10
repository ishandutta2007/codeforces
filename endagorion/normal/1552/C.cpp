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
        int n, k;
        cin >> n >> k;
        vector<pii> p;
        vi f(2 * n);
        forn(i, k) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            if (x > y) swap(x, y);
            f[x] = f[y] = 1;
            p.pb({x, y});
        }

        int ans = (n - k) * (n - k - 1) / 2;
        forn(i, k) forn(j, i) {
            pii q = {max(p[i].fi, p[j].fi), min(p[i].se, p[j].se)};
            if (q.fi > q.se) continue;
            if (q == p[i] || q == p[j]) continue;
            ++ans;
        }
        forn(i, k) {
            int ins = 0;
            fore(x, p[i].fi + 1, p[i].se - 1) if (!f[x]) ++ins;
            uin(ins, 2 * (n - k) - ins);
            ans += ins;
        }
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}