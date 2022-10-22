#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <time.h>
#include <queue>

using namespace std;

const int MAXN = 2e5 + 7;

vector <int> g[MAXN];
int cnt[MAXN];

void dfs(int u, int parent, int h) {
    ++cnt[h];
    for (int v : g[u]) {
        if (v == parent) continue;
        dfs(v, u, h + 1);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    for (int u = 1; u < n; ++u) {
        int v;
        cin >> v;
        g[u].push_back(v - 1);
        g[v - 1].push_back(u);
    }

    dfs(0, -1, 0);

    int ans = 0;
    for (int i = 0; i < MAXN; ++i) {
        ans += (cnt[i] % 2);
    }

    cout << ans << '\n';

    return 0;
}