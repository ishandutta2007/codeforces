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

using namespace std;

typedef long long ll;

vector <vector <int>> g;

int ans = 0;

int dfs(int u, int p) {
    int sum = 1;
    for (auto v : g[u]) {
        if (v != p) sum += dfs(v, u);
    }
    if (sum % 2 == 0 && p != -1) ++ans;
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    g.resize(n);
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (n % 2 == 1) {
        cout << -1 << '\n';
        return 0;
    }
    dfs(0, -1);
    cout << ans << '\n';
}