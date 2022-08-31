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
        vvi e(n);
        forn(i, m) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            e[x].pb(y);
            e[y].pb(x);
        }
        vi st(n, -1);
        set<int> q0 = {0};
        vi ans;
        while (!q0.empty()) {
            int v = *q0.begin();
            q0.erase(v);
            st[v] = 0;
            ans.pb(v);
//            cerr << v << '\n';
            for (int u: e[v]) {
                assert(st[u]);
                if (st[u] == 1) continue;
                st[u] = 1;
                if (q0.count(u)) q0.erase(u);
                for (int w: e[u]) {
                    if (st[w] != -1) continue;
                    q0.insert(w);
                }
            }
        }

        bool ok = !count(all(st), -1);
        if (!ok) cout << "NO\n";
        else {
            cout << "YES\n";
            sort(all(ans));
            cout << ans.size() << '\n';
            for (int x: ans) cout << x + 1 << ' ';
            cout << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}