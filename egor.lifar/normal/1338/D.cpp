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
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define rank rank228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int MAXN = 100229;


int n;
vector<int> g[MAXN];
int dp[MAXN][2];
int ans = 0;


void dfs(int u, int pr = -1) {
    dp[u][0] = sz(g[u]) - 1;
    dp[u][1] = 1;
    for (auto h: g[u]) {
        if (h != pr) {
            dfs(h, u);
            chkmax(dp[u][1], dp[h][0] + 1);
            chkmax(dp[u][0], max(dp[h][0], dp[h][1]) + sz(g[u]) - 2);
        }
    }
    chkmax(ans, dp[u][0] + 1);
    chkmax(ans, dp[u][1]);
    int lmx1 = 0, lmx2 = 0, rmx1 = 0, rmx2 = 0;
    int cnt = 0;
    for (auto h: g[u]) {
        if (h != pr) {
            cnt++;
            int val = dp[h][0];
            int val1 = max(dp[h][0], dp[h][1]);
            if (lmx1 < val) {
                lmx2 = lmx1;
                lmx1 = val;
            } else {
                chkmax(lmx2, val);
            }
            if (rmx1 < val1) {
                rmx2 = rmx1;
                rmx1 = val1;
            } else {
                chkmax(rmx2, val1);
            }
        }
    }
    if (cnt >= 2) {
        chkmax(ans, rmx1 + rmx2 + sz(g[u]) - 2);
        chkmax(ans, lmx1 + lmx2 + 1);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    cin >> n;
    for (int i = 0; i <n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0); 
    cout << ans << '\n';
}