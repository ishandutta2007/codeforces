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
int a[maxn], inva[maxn];
int tin[maxn], tout[maxn], h[maxn];
int par[maxn];
int b[maxn];
vi inord, outord;
vi e[maxn];

void dfs0(int v) {
    tin[v] = inord.size();
    inord.pb(v);

    for (int u: e[v]) {
        h[u] = h[v] + 1;
        par[u] = v;
        dfs0(u);
    }
    tout[v] = outord.size();
    outord.pb(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n;
    forn(i, n) {
        cin >> a[i], --a[i];
        inva[a[i]] = i;
    }
    forn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].pb(v);
    }

    forn(i, n) sort(all(e[i]), [&](int v, int u){return a[v] < a[u];});

    dfs0(0);

    forn(i, n) b[i] = -1;
    int x = a[0] - 1;
    i64 ans = 0;
    bool ok = true;
    if (x >= 0) {
        forn(j, x) {
            b[outord[j]] = j;
            ans += h[outord[j]];
        }
        int H = h[inva[x]];
        ans += H;
        int C = x;
        for (int v: inord) if (b[v] == -1) b[v] = C++;

        int v = 0;
        forn(i, H) {
            auto it = lower_bound(all(e[v]), v, [&](int u, int v){return b[u] < b[v];});
            if (it == e[v].end()) {
                ok = false;
                break;
            }
            swap(b[v], b[*it]);
            v = *it;
        }
    } else forn(i, n) b[i] = tin[i];

    forn(i, n) ok &= a[i] == b[i];
    if (!ok) cout << "NO\n";
    else  {
        cout << "YES\n" << ans << '\n';
        forn(i, n) cout << tin[i] + 1 << ' ';
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}