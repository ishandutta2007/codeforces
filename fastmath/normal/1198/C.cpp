#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int, int>
#define app push_back
const int N = 5e5 + 7;
vector <ii> g[N];
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= 3 * n; ++i) g[i].clear();
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v; g[u].app({v, i + 1}); g[v].app({u, i + 1});
    }   
    set <int> mat, ind;
    for (int u = 1; u <= 3 * n; ++u) {
        bool add = 1;
        for (auto e : g[u]) {
            if (ind.find(e.first) != ind.end()) {
                ind.erase(e.first);
                mat.insert(e.second);
                add = 0;
                break;
            }   
        }   
        if (add) ind.insert(u);
        if (mat.size() >= n) {
            cout << "Matching\n";
            for (int e : mat) cout << e << ' ';
            cout << '\n';
            return;
        }
        if (ind.size() >= n) {
            cout << "IndSet\n";
            for (int e : ind) cout << e << ' ';
            cout << '\n';
            return;
        }   
    }   
    exit(1);
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) solve();
}