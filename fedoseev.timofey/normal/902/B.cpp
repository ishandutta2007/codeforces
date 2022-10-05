#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;

long long ans = 1;
vector <vector <int>> g;
vector <int> c;

void dfs(int u, int color, int p) {
    for (auto v : g[u]) {
        if (v == p) continue;
        if (c[v] == color) {
            dfs(v, color, u);
        }
        else {
            ++ans;
            dfs(v, c[v], u);
        }
    }
}

int main() {
    int n;
    cin >> n;
    g.resize(n);
    c.resize(n);
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        g[i].push_back(x);
        g[x].push_back(i);
    }
    for (int i = 0; i < n; ++i) cin >> c[i];
    dfs(0, c[0], -1);
    cout << ans << endl;
}