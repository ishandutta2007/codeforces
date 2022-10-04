#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 7;

vector <int> g[N];
vector <int> p;

bool used[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) sort(g[i].begin(), g[i].end());
    set <int> can;
    can.insert(0);
    used[0] = 1;
    vector <int> res;
    while (!can.empty()) {
        int u = *can.begin();
        can.erase(can.begin());
        res.push_back(u + 1);
        for (auto v : g[u]) {
            if (!used[v]) {
                can.insert(v);
                used[v] = 1;
            }
        }
    }
    for (auto x : res) {
        cout << x << ' ';
    }
}