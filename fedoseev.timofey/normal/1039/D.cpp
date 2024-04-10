#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 7;
const int Inf = 1e9;

vector <int> g[N];

int dp[2][N];
int par[N];
vector <int> ord;

void dfs(int u, int p) {
    par[u] = p;
    for (auto v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    ord.push_back(u);
}

int f(int k) {
    for (int u : ord) {
        int cnt = 0;
        for (auto v : g[u]) cnt += (v != par[u]);
        if (!cnt) {
            dp[0][u] = (k == 1);
            dp[1][u] = (k != 1);
            continue;
        }
        int sum = 0;
        int mx1 = -Inf, mx2 = -Inf;
        for (auto v : g[u]) {
            if (v == par[u]) continue;
            sum += dp[0][v];
            if (dp[1][v] >= mx1) {
                mx2 = mx1;
                mx1 = dp[1][v];
            }
            else if (dp[1][v] > mx2) {
                mx2 = dp[1][v];
            }
        }
        dp[0][u] = sum + ((mx1 + 1) >= k);
        dp[1][u] = ((mx1 + 1 >= k) ? mx1 + 1 - k : mx1 + 1);
        if (sum + ((mx1 + mx2 + 1) >= k) > dp[0][u]) {
            dp[0][u] = sum + ((mx1 + mx2 + 1) >= k);
            dp[1][u] = 0;
        }
    }
    return dp[0][0];
}

int res[N];

void rec(int l, int r, int lb, int ub) {
    if (l > r) return;
    if (lb == ub) {
        for (int i = l; i <= r; ++i) {
            res[i] = lb;
        }
        return;
    }
    int m = (l + r) >> 1;
    int val = f(m);
    res[m] = val;
    rec(l, m - 1, lb, val);
    rec(m + 1, r, val, ub);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1);
    rec(1, n, n, 0);
    for (int i = 1; i <= n; ++i) {
        cout << res[i] << '\n';
    }
}