#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 7;

vector <int> g[N];
int sz[N];

int dfs(int u) {
    for (auto v : g[u]) {
        sz[u] += dfs(v);
    }
    if (!sz[u]) sz[u] = 1;
    return sz[u];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        g[p].push_back(i);
    }
    dfs(0);
    vector <int> have;
    for (int i = 0; i < n; ++i) have.push_back(sz[i]);
    sort(have.begin(), have.end());
    for (int i = 0; i < n; ++i) {
        cout << have[i] << ' ';
    }
}