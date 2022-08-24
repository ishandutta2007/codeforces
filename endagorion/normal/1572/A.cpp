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
        cin >> n;
        vvi e(n), re(n);
        forn(i, n) {
            int k;
            cin >> k;
            forn(j, k) {
                int x;
                cin >> x;
                --x;
                e[x].pb(i);
                re[i].pb(x);
            }
        }
        set<int> sources;
        vi indeg(n);
        forn(i, n) {
            indeg[i] = re[i].size();
            if (!indeg[i]) sources.insert(i);
        }
        int lb = 0, ans = 1;
        vi vis(n);
        while (!sources.empty()) {
            auto it = sources.lower_bound(lb);
            if (it == sources.end()) it = sources.begin(), ++ans;
            int v = *it;
            vis[v] = 1;
            sources.erase(v);
            for (int u: e[v]) {
                if (vis[u]) continue;
                --indeg[u];
                if (indeg[u] == 0) sources.insert(u);
            }
            lb = v;
        }
        if (count(all(vis), 0)) ans = -1;
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}