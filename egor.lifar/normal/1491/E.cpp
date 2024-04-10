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
const int Mod = 1000000009;


int sum(int a, int b) {
    return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
    return ((ll)a * b) % Mod;
}


int powm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}


int inv(int a) {
    return powm(a, Mod - 2);
}



const int MAXN = 200229;


int n;
set<int> g[MAXN];
int f[90];
int sz[MAXN];
int tp = -1;
vector<int> st;
int prs[MAXN];
mt19937 as;


void dfs(int u, int pr = -1) {
    sz[u] = 1;
    int cnt = 0;
    for (auto h: g[u]) {
        if (h != pr) {
            cnt++;
            dfs(h, u);
            prs[h] = u;
            st.pb(h);
            sz[u] += sz[h];
        }
    }
    chkmax(tp, sz(g[u]));
}

bool tryit(int u, int id) {
    st.clear();
    tp = -1;
    dfs(u);
    if (sz[u] != f[id]) {
        return false;
    }
    if (sz[u] <= 3) {
        return true;
    }
    // if (tp <= 2) {
    //     return true;
    // }
    vector<pair<int, int> > pd, pd1;
    for (auto h: st) {
        if (sz[h] == f[id - 1]) {
            pd.pb(mp(prs[h], h));
        } else if (sz[h] == f[id - 2]) {
            pd1.pb(mp(prs[h], h));
        }
    }
    shuffle(all(pd), as);
    shuffle(all(pd1), as);
    for (auto y: pd) {
        g[y.first].erase(y.second);
        g[y.second].erase(y.first);
        if (tryit(y.first, id - 2) && tryit(y.second, id - 1)) {
            return true;
        }
        g[y.first].insert(y.second);
        g[y.second].insert(y.first);
    }
    for (auto y: pd1) {
        g[y.first].erase(y.second);
        g[y.second].erase(y.first);
        if (tryit(y.first, id - 1) && tryit(y.second, id - 2)) {
            return true;
        }
        g[y.first].insert(y.second);
        g[y.second].insert(y.first);
    }
    return false;
}
 

void solve() {
    cin >> n;
    for (int it = 0; it < n - 1; it++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].insert(b);
        g[b].insert(a);
    }
    if (n <= 3) {
        cout << "YES\n";
        return;
    }
    f[0] = f[1] = 1;
    for (int i = 2; i <= 30; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    int id = -1;
    for (int i = 0; i <= 30; i++) {
        if (f[i] == n) {
            id = i;
        }
    }
    if (id == -1) {
        cout << "NO\n";
        return;
    }
    if (tryit(0, id)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 //read(FILENAME);
    int t;
  //  cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}