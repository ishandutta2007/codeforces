#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
 
using namespace std;
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
using ll = long long;
using ld = long double; 
const string FILENAME = "input";
const int MAXN = 200228;


int n, m;
vector<pair<int, int> > g[MAXN];
vector<int> z[MAXN];
vector<pair<int, int> > kek;
int parent[MAXN];
int c[MAXN];
bool used[MAXN];


int findset(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = findset(parent[v]);
}



vector<pair<int, pair<int, int> > > res;


void dfs(int u, int pr = -1) {
    for (auto h: g[u]) {
        if (h.first == pr) {
            continue;
        }
        if (h.second != -1) {
            int t = __builtin_popcount(h.second) & 1;
            if (t == 0) {
                parent[findset(h.first)] = findset(u);
            } else {
                kek.pb(mp(h.first, u));
            }
        }
        dfs(h.first, u);
    }
}



bool bad = false;


void mark(int u) {
    used[u] = true;
    for (auto h: z[u]) {
        if (!used[h]) {
            c[h] = c[u] ^ 1;
            mark(h);
        } else {
            if (c[h] != (c[u] ^ 1)) {
                bad = true;
            }
        }
    }
}

void dfsb(int u, int pr = -1) {
    int ru = findset(u);
    for (auto h: g[u]) {
        if (h.first == pr) {
            continue;
        }
        int rh = findset(h.first);
        int ph = h.second;
        if (h.second == -1) {
            if (used[rh]) {
                h.second = (c[rh] == c[ru] ? 0: 1);
                res.pb(mp(u, mp(h.first, (c[rh] == c[ru] ? 0: 1))));
            } else {
                c[rh] = c[ru];
                h.second = 0;
                res.pb(mp(u, mp(h.first, 0)));
                mark(rh);
            }
        } else {
            res.pb(mp(u, h));
            int t = __builtin_popcount(h.second) & 1;
            if (used[rh]) {
                if (c[rh] != (c[ru] ^ t)) {
                    bad = true;
                }
            } else {
                c[rh] = c[ru] ^ t;
                mark(rh);
            }
        }
        // if (!bad) {
        //     cout <<ph << ' ' << c[rh] << ' ' << c[ru] << endl;
        //     if (!(c[rh] == (c[ru] ^ (__builtin_popcount(h.second) & 1)))) {
        //         exit(0);
        //     }
        // }
        dfsb(h.first, u);
    }
}


void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        g[i].clear();
        z[i].clear();
        used[i] = false;
        c[i] = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        x--, y--;
        g[x].pb(mp(y, v));
        g[y].pb(mp(x, v));
    }
    kek.clear();
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    res.clear();
    dfs(0);
    vector<pair<pair<int, int>, int> > gg;
    for (int i = 0; i < m; i++) {
        int a, b, p;
        cin >> a >> b >> p;
        a--, b--;
        gg.pb(mp(mp(a, b), p));
        if (p == 1) {
            kek.pb(mp(a, b));
        } else {
            parent[findset(a)] = findset(b);
        }
    }
    for (auto x: kek) {
        int d = findset(x.first);
        int d1 = findset(x.second);
        if (d == d1) {
            cout << "NO\n";
            return;
        }   
        z[d].pb(d1);
        z[d1].pb(d);
    }
    bad = false;
    mark(findset(0));
    dfsb(0);
    for (auto t: gg) {
        int r = c[findset(t.first.first)] ^ c[findset(t.first.second)];
        if (r != t.second) {
            bad = true;
        }
    }
    if (bad) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (auto x: res) {
        cout << x.first + 1 << ' ' << x.second.first + 1 << ' ' << x.second.second << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}