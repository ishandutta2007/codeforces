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
const int MAXN = 2005;


int n, m;
vector<pair<int, int> > g[MAXN];  
int used[MAXN];


void dfs(int u, int c = 1) {
    used[u] = c;
    for (auto h: g[u]) {
        if (!used[h.first]) {
            dfs(h.first, 3 - c);
        } else if (used[h.first] == used[u]) {
            cout << "NO\n";
            exit(0);
        }
    }
}  


int dist[MAXN][MAXN];


void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        if (c == 1) {
            g[a].pb(mp(b, 1));
            g[b].pb(mp(a, -1));
        } else {
            g[a].pb(mp(b, 1));
            g[b].pb(mp(a, 1));
        }
    }    
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = 10000;
        }
    }
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
        for (auto h: g[i]) {
            dist[i][h.first] = h.second;
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                chkmin(dist[i][j], dist[i][k] + dist[k][j]);
                if (dist[i][j] < -3 * n) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    int opt = -1;
    int pos = -1;
    for (int i = 0; i < n; i++) {
        int tk = -1e9;
        int tk1 = 1e9;
        for (int j = 0; j < n; j++) {
            chkmax(tk, dist[i][j]);
            chkmin(tk1, dist[i][j]);
        }
        if (tk - tk1 > opt) {
            opt = tk - tk1;
            pos = i;
        }
    }
    if (pos == -1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int tp = 1e9;
    int tp1 = -1e9;
    for (int j = 0; j < n; j++) {
        chkmax(tp1, dist[pos][j]);
        chkmin(tp, dist[pos][j]);
    }
    cout << tp1 - tp << '\n';
    for (int j = 0; j < n; j++) {
        cout << dist[pos][j] - tp << ' ';
    }
    cout << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    int t;
   // cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}