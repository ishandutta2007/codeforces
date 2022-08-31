#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
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
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 110000;
multiset<int> e[maxn];
int n, m;
int col[maxn];
vi te[maxn];

void add_diag(int a, int b) {
    e[a].insert((b - a + n) % n);
    e[b].insert((a - b + n) % n);
}

int dfs(int v, int p = -1) {
    int m1 = 0, m2 = 0;
    for (int u: te[v]) {
        if (u == p) continue;
        int m = dfs(u, v);
        m2 |= m & m1;
        m1 |= m;
    }
    int res = 0;
    while (((m1 >> res) & 1) || (m2 >> res)) ++res;
    col[v] = res;
//    cerr << v << ' ' << m1 << ' ' << m2 << ' ' << res << '\n';
    return (m1 | (1 << res)) & ~((1 << res) - 1);
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
    forn(i, n) add_diag(i, (i + 1) % n);
    forn(i, m) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        forn(j, 2) add_diag(a, b);
    }

    vvi regs;
    forn(i, n) {
        while (!e[i].empty()) {
            vi reg;
            int v = i, d = *e[v].begin();
            while (1) {
                reg.pb(v);
//                int dd = *e[v].begin();
                int u = (v + d) % n;
                e[v].erase(e[v].find(d));
                e[u].erase(e[u].find(n - d));
                v = u; d = n - d;
                if (v == i) break;
                d = *(--e[u].lower_bound(d));
            }
            sort(rall(reg));
            regs.pb(reg);
        }
    }
    sort(all(regs));
    map<pii, vi> edges;
//    for (auto w: regs) {
    forn(j, regs.size()) {
        auto &w = regs[j];
        forn(i, w.size()) {
            int v = w[i], u = w[(i + 1) % w.size()];
            if (v > u) swap(v, u);
            if (u - v == 1 || u - v == n - 1) continue;
            edges[{v, u}].pb(j);
        }
    }

    for (auto w: edges) {
        assert(w.se.size() == 2);
        te[w.se[0]].pb(w.se[1]);
        te[w.se[1]].pb(w.se[0]);
//        cerr << w.se[0] << ' ' << w.se[1] << '\n';
    }

    for (auto w: regs) {
        for (int x: w) cerr << x << ' ';
        cerr << '\n';
    }

    dfs(0);
    forn(i, regs.size()) cout << 20 - col[i] << ' ';
    cout << '\n';


#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}