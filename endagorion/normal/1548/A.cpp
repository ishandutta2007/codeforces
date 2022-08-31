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
set<int> f[maxn];

int is_alive(int i) {
    return int(*f[i].rbegin()) < i;
}

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
    forn(i, n) f[i] = {-1};
    forn(i, m) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        f[x].insert(y);
        f[y].insert(x);
    }

    int alive = 0;
    forn(i, n) if (is_alive(i)) ++alive;
    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            alive -= is_alive(u) + is_alive(v);
            f[u].insert(v);
            f[v].insert(u);
            alive += is_alive(u) + is_alive(v);
        } else if (type == 2) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            alive -= is_alive(u) + is_alive(v);
            f[u].erase(v);
            f[v].erase(u);
            alive += is_alive(u) + is_alive(v);
        } else cout << alive << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}