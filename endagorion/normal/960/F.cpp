#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

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

struct TEdge {
    int u, v, w;
};

int fenw_max(vi &f, int i) {
    int s = 0;
    for (; i >= 0; i &= i + 1, --i) uax(s, f[i]);
    return s;
}

void fenw_upd(vi &f, int i, int x) {
    for (; i < f.size(); i |= i + 1) uax(f[i], x);
}

int index(vi &v, int x) {
    return lower_bound(all(v), x) - v.begin();
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
    vector<TEdge> e(m);
    vvi lst(n), f(n);
    forn(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        e[i] = {u, v, w};
        lst[u].pb(w);
        lst[v].pb(w);
    }

    forn(i, n) {
        sort(all(lst[i]));
        lst[i].erase(unique(all(lst[i])), lst[i].end());
        f[i].resize(lst[i].size());
    }

    forn(i, m) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        int iu = index(lst[u], w), iv = index(lst[v], w);
//        fenw_upd(f[u], iu, fenw_max(f[v], iv - 1) + 1);
        fenw_upd(f[v], iv, fenw_max(f[u], iu - 1) + 1);
    }

    int ans = 0;
    forn(i, n) uax(ans, fenw_max(f[i], (int)f[i].size() - 1));
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}