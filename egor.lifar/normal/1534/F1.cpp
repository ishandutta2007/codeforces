/*
KAMUI!
 
 

 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

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
const int Mod = 998244353;


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
 


const int MAXN = 400228; 


int n, m;
string s[MAXN];
int a[MAXN];
vector<int> g[MAXN], rg[MAXN];
bool used[MAXN];
vector<int> last[MAXN];
int c[MAXN];
bool good[MAXN];


void add(int i, int j, int i1, int j1) {
    g[i * m + j].pb(i1 * m + j1);
    rg[i1 * m + j1].pb(i * m + j);
}   



vector<int> order;


void dfs(int u) {
    used[u] = true;
    for (auto h: g[u]) {
        if (!used[h]) {
            dfs(h);
        }
    }
    order.pb(u);
}


void dfs1(int u, int k) {
    used[u] = true;
    c[u] = k;
    for (auto h: rg[u]) {
        if (!used[h]) {
            dfs1(h, k);
        }
    }
}



void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                if (i && s[i - 1][j] == '#') {
                    add(i, j, i - 1, j);
                }
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        last[i].resize(m);
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                last[i][j] = i;
            } else {
                last[i][j] = (i == n - 1 ? -1: last[i + 1][j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                if (j) {
                    if (last[i][j - 1] != -1) {
                        add(i, j, last[i][j - 1], j - 1);
                    }
                }
                if (j + 1 < m) {
                    if (last[i][j + 1] != -1) {
                        add(i, j, last[i][j + 1], j + 1);
                    }
                }
                if (i + 1 < n && last[i + 1][j] != -1) {
                    add(i, j, last[i + 1][j], j);
                }
            }
        }
    }
    for (int i = 0; i < n * m; i++) {
        if (!used[i] && s[i / m][i % m] == '#') {
            dfs(i);
        }
    }
    reverse(all(order));
    memset(used, 0, sizeof(used));
    int it = 0;
    for (auto x: order) {
        if (!used[x]) {
            it++;
            dfs1(x, it);
        }
    }
    for (int i = 0; i < n * m; i++) {
        for (auto h: g[i]) {
            if (c[i] != c[h]) {
                good[c[h]] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= it; i++) {
        if (!good[i]) {
            ans++;
        }
    }
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    int t;
    t = 1;
  //  cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}