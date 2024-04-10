#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 7;

bool ok[N];
vector <int> g[N];

ll ans = 0;

int k;

int dfs(int u, int p = -1) {
    int sum = ok[u];
    for (auto v : g[u]) {
        if (v != p) sum += dfs(v, u);
    }
    ans += min(sum, 2 * k - sum);
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n >> k;
    for (int i = 0; i < 2 * k; ++i) {
        int v;
        cin >> v;
        ok[v - 1] = 1;
    }
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    cout << ans << '\n';
}