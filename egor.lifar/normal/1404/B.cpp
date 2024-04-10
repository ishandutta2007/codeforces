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
const int MAXN = 100228;
 
 
 
int n;
int a, b, da, db;
vector<int> g[MAXN];
int dist[MAXN], dist1[MAXN];
int dist2[MAXN];

 
void dfs(int u, int pr = -1) {
    for (auto h: g[u]) {
        if (h != pr) {
            dist[h] = dist[u] + 1;
            dfs(h, u);
        }
    }
}
 
 
void dfs1(int u, int pr = -1) {
    for (auto h: g[u]) {
        if (h != pr) {
            dist1[h] = dist1[u] + 1;
            dfs1(h, u);
        }
    }
}
 
 
void dfs2(int u, int pr = -1) {
    for (auto h: g[u]) {
        if (h != pr) {
            dist2[h] = dist2[u] + 1;
            dfs2(h, u);
        }
    }
} 

 
void solve() {
    cin >> n >> a >> b >> da >> db;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }
    for (int i = 0; i < n - 1; i++) {
        int c, d;
        cin >> c >> d;
        g[c].pb(d);
        g[d].pb(c);
    }
    dist[a] = 0;
    dfs(a);
    dist1[b] = 0;
    dfs1(b);
    int opt = 1;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > dist[opt]) {
            opt = i;
        }
    }
    dist2[opt] = 0;
    dfs2(opt);
    int kek = 0;
    for (int i = 1; i <= n; i++) {
        chkmax(kek, dist2[i]);
    }
    if (dist[b] <= da) {
        cout << "Alice\n";
        return;
    }
    if (db <= 2 * da) {
        cout << "Alice\n";
        return;
    }
    if (kek <= 2 * da) {
        cout << "Alice\n";
        return;
    }
    cout << "Bob\n";
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 //  read(FILENAME);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}