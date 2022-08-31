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

    int n, m;
    cin >> n >> m;
    vi64 bal(n);
    forn(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        bal[u] -= w;
        bal[v] += w;
    }

    vi ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j){return bal[i] < bal[j];});

    vector<pii> e;
    vi64 d;
    int L = 0, R = n - 1;
    while (L < R) {
        if (!bal[ord[L]]) ++L;
        else if (!bal[ord[R]]) --R;
        else {
            i64 z = min(-bal[ord[L]], bal[ord[R]]);
            bal[ord[L]] += z;
            bal[ord[R]] -= z;
            e.pb({ord[L], ord[R]});
            d.pb(z);
        }
    }

    cout << e.size() << '\n';
    forn(i, e.size()) cout << e[i].fi + 1 << ' ' << e[i].se + 1 << ' ' << d[i] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}