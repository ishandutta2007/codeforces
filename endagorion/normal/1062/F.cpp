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

const int maxn = 310000;
vi e[2][maxn];
int vis[maxn];

vi ord;

void dfs_ord(int v) {
    if (vis[v]) return;
    vis[v] = 1;
    for (int u: e[0][v]) dfs_ord(u);
    ord.pb(v);
}

int n, m;

vi unreach(vi ord, int z) {
    vi outd(n);
    vi in1(n);
    forn(v, n) in1[v] = e[z ^ 1][v].size();
    vector<set<int>> sources(2);

    vi vis(n);
    vi ans(n);

    for (int v: ord) {
        for (int u: e[z ^ 1][v]) {
            ++outd[u];
            if (outd[u] == 1) {
                sources[min(in1[u], 1)].erase(u);
            }
            if (outd[u] == 2) {
                for (int w: e[z][u]) {
                    --in1[w];
                    if (!in1[w] && vis[w] && !outd[w]) {
                        sources[1].erase(w);
                        sources[0].insert(w);
                    }
                }
            }
        }
        vis[v] = 1;
        ans[v] = sources[0].size() + 2 * sources[1].size();
        sources[min(in1[v], 1)].insert(v);
    }
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

    cin >> n >> m;
    forn(i, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[0][u].pb(v);
        e[1][v].pb(u);
    }

    forn(i, n) dfs_ord(i);
    reverse(all(ord));

    vvi ans(2);
    ans[0] = unreach(ord, 0);
    reverse(all(ord));
    ans[1] = unreach(ord, 1);

    int cnt = 0;
    forn(v, n) if (ans[0][v] + ans[1][v] <= 1) ++cnt;
    cout << cnt << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}