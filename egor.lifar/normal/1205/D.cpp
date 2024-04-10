/*














 */
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
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { x = (x > y ? y: x);}
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { x = (x < y ? y: x);}
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left224
#define right right224
#define next next224
#define rank rank224
#define prev prev224
#define y1 y1224
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
const string FILENAME = "input";
const int MAXN = 1005;


int n;
vector<int> g[MAXN];
int sz[MAXN];
vector<int> st;
int deep[MAXN];


void dfs(int u, int pr = -1) {
    sz[u] = 1;
    st.pb(u);
    for (auto h: g[u]) {
        if (h == pr) {
            continue;
        }
        deep[h] = deep[u] + 1;
        dfs(h, u);
        sz[u] += sz[h];
    }   
}


void dfs1(int u, int pr = -1) {
    sz[u] = 1;
    for (auto h: g[u]) {
        if (h == pr) {
            continue;
        }
        dfs1(h, u);
        sz[u] += sz[h];
    }   
}


int c, c1;
int cs = 0;
long long geg[MAXN];


void dfs2(int u, int pr = -1) {
    cs++;
    geg[u] = cs;
    cout << pr + 1 << ' ' << u + 1 << ' ' << geg[u] - geg[pr] << '\n';
    for (auto h: g[u]) {
        if (h == pr) {
            continue;
        }
        dfs2(h, u);
    }   
}


void dfs3(int u, int pr = -1) {
    cs++;
    geg[u] = 1LL * cs * (c + 1);
    cout << pr + 1 << ' ' << u + 1 << ' ' << geg[u] - geg[pr] << '\n';
    for (auto h: g[u]) {
        if (h == pr) {
            continue;
        }
        dfs3(h, u);
    }   
}


int main() {
    ios_base::sync_with_stdio(false);
   // read(FILENAME); 
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0);
    int pos = -1;
    reverse(all(st));
    for (auto x: st) {
        if (sz[x] >= (n + 1) / 2 && (pos == -1 || deep[pos] < deep[x])) {
            pos = x;
        }
    }
    assert(pos != -1);
    set<pair<int, vector<int> > > sts;
    memset(sz, 0, sizeof(sz));
    for (auto h: g[pos]) {
        dfs1(h, pos);
        sts.insert({sz[h], {h}});
    }
    while (sz(sts) > 2) {
        auto x = *sts.begin();
        sts.erase(x);
        auto y = *sts.begin();
        sts.erase(y);
        auto z = x;
        x.first += y.first;
        for (auto f: y.second) {
            x.second.pb(f);
        }
        sts.insert(x);
    }
    int id = 0;
    vector<int> st;
    for (auto x: sts) {
        if (id == 0) {
            c = x.first;
        }
        for (auto y: x.second) {
            st.pb(y);
        }
        id++;
    }
    bool was = false;
    for (auto h: st) {
        if (cs < c && !was) {
            dfs2(h, pos);
        } else {
            if (!was) {
                cs = 0;
                was = true;
            }
            dfs3(h, pos);
        }
    }
    return 0; 
}