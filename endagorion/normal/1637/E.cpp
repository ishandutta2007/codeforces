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
        cin >> n >> m;
        vi a(n);
        forn(i, n) cin >> a[i];
        vi vals = a;
        sort(all(vals));
        vals.erase(unique(all(vals)), vals.end());
        int V = vals.size();
        auto index = [&](int x) {
            return lower_bound(all(vals), x) - vals.begin();
        };
        vi cnt(V);
        forn(i, n) ++cnt[index(a[i])];
        vvi byCnt(n + 1);
        forn(i, V) byCnt[cnt[i]].pb(i);
        forn(i, n + 1) reverse(all(byCnt[i]));

        vector<map<int, vi> > bad(V);
        forn(i, V) bad[i][cnt[i]].pb(i);
        forn(i, m) {
            int x, y;
            cin >> x >> y;
            x = index(x); y = index(y);
            bad[x][cnt[y]].pb(y);
            bad[y][cnt[x]].pb(x);
        }
        forn(i, V) for (auto &[c, v]: bad[i]) sort(rall(v));

        vi difc;
        forn(c, n + 1) if (!byCnt[c].empty()) difc.pb(c);

        i64 ans = 0;
        forn(i, V) for (int c: difc) {
            if (!bad[i].count(c)) {
                int j = byCnt[c][0];
                i64 res = 1LL * (cnt[i] + c) * (vals[i] + vals[j]);
//                cerr << i << ' ' << j << ' ' << vals[i] << ' ' << vals[j] << ' ' << res << '\n';
                uax(ans, res);
                continue;
            }
            auto &v = bad[i][c];
            forn(p, byCnt[c].size()) {
                if (p < v.size() && v[p] == byCnt[c][p]) continue;
                int j = byCnt[c][p];
                i64 res = 1LL * (cnt[i] + c) * (vals[i] + vals[j]);
//                cerr << i << ' ' << j << ' ' << vals[i] << ' ' << vals[j] << ' ' << res << '\n';
                uax(ans, res);
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