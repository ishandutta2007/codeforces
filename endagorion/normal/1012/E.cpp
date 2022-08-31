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

const int maxn = 210000;
int a[maxn], to[maxn];
int par[maxn];

int root(int x) {
    return x == par[x] ? x : par[x] = root(par[x]);
}

vvi cycles;

void apply_cycle(vi cycle) {
    if (cycle.size() <= 1) return;
//    cerr << cycle.size() << '\n';
    cycles.pb(cycle);
    vi tos(cycle.size());
    forn(i, cycle.size()) tos[i] = to[cycle[i]];
//    rotate(tos.begin(), 1 + all(tos));
    rotate(all(tos) - 1, tos.end());
    forn(i, cycle.size()) to[cycle[i]] = tos[i];
}

int vis[maxn];

vi get_cycle(int i) {
    vi cycle;
    for (int j = i; !vis[j]; j = to[j]) vis[j] = 1, cycle.pb(j);
    return cycle;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, s;
    cin >> n >> s;
    forn(i, n) cin >> a[i];
    vi b(a, a + n);
    sort(all(b));
    vector<pii> p;
    vi pos;
    forn(i, n) if (a[i] != b[i]) p.pb({a[i], i}), pos.pb(i);
    sort(all(p));
    forn(i, n) par[i] = to[i] = i;
    forn(i, p.size()) to[p[i].se] = pos[i];
    forn(i, n) {
        if (root(i) != root(to[i])) par[root(i)] = par[root(to[i])];
    }

//    forn(i, n) cerr << to[i] << ' ';
//    cerr << '\n';

    map<int, vi> byv;
    forn(i, n) byv[a[i]].pb(i);
    for (auto [x, v]: byv) {
        int repr = -1;
        for (int i: v) {
            if (to[i] == i) continue;
            if (repr == -1) repr = i;
            else if (root(i) != root(repr)) {
                swap(to[i], to[repr]);
                par[root(repr)] = root(i);
            }
        }
    }

    int S = 0;
    forn(i, n) if (to[i] != i) ++S;

    if (S > s) {
        cout << -1 << '\n';
        return 0;
    }

    vi reprs;
    forn(i, n) if (to[i] != i && par[i] == i) reprs.pb(i);
    int ops = min((int)reprs.size(), s - S);
    if (ops < 3) ops = 0;
    reprs.resize(ops);
    
    apply_cycle(reprs);
    forn(i, n) {
        if (to[i] == i || vis[i]) continue;
        apply_cycle(get_cycle(i));
    }

    forn(i, n) assert(to[i] == i);

    cout << cycles.size() << '\n';
    for (auto v: cycles) {
        cout << v.size() << '\n';
        for (int x: v) cout << x + 1 << ' ';
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}