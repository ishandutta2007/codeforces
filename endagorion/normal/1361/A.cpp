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

const int maxn = 510000;
vi e[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m;
    cin >> n >> m;
    forn(i, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].pb(v);
        e[v].pb(u);
    }

    vi top(n);
    forn(i, n) cin >> top[i], --top[i];
    vi ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int u, int v) {return top[u] < top[v];});

    bool ok = true;
    forn(i, n) if (top[i] > e[i].size()) ok = false;
    if (ok) {
        vi ctop(n, -1);
        for (int v: ord) {
            vi used(top[v] + 1);
            for (int u: e[v]) {
                if (ctop[u] == -1 || ctop[u] >= used.size()) continue;
                used[ctop[u]] = 1;
            }
            forn(i, used.size()) ok &= (used[i] == 0) == (i == top[v]);
            ctop[v] = top[v];
        }
    }

    if (!ok) cout << -1;
    else for (int v: ord) cout << v + 1 << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}