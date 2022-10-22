#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <random>

using namespace std;

const int MOD = 1000 * 1000 * 1000 + 9;
const int INF = 1e9 + 7;

const int MAXN = 2e5 + 7;

vector <int> g[MAXN];
bool dp[MAXN];

void jfs(int u, int parent) {
    int cnt = 0;
    for (int v : g[u]) {
        if (v == parent) continue;
        jfs(v, u);
        cnt += dp[v];
    }
    dp[u] = ((cnt % 2) ^ (u != parent));
}

void print(int u, int parent) {
    for (int v : g[u]) {
        if (v == parent) continue;
        if (!dp[v]) print(v, u);
    }
    cout << u + 1 << '\n';
    for (int v : g[u]) {
        if (v == parent) continue;
        if (dp[v]) print(v, u);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        if (p) {
            g[p - 1].push_back(i);
            g[i].push_back(p - 1);
        }
    }
    
    jfs(0, 0);
    
    if (dp[0]) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        print(0, 0);
    }

    return 0;
}