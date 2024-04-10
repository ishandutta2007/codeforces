#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), u(q), v(q), x(q);
    for (int i = 0; i < q; i += 1) {
        cin >> u[i] >> v[i] >> x[i];
        if (u[i] > v[i]) swap(u[i], v[i]);
    }
    for (int i = 0; i < 30; i += 1) {
        vector<int> ban(n + 1);
        vector<vector<int>> R(n + 1);
        for (int j = 0; j < q; j += 1) {
            if ((x[j] >> i) % 2 == 0) {
                ban[u[j]] = ban[v[j]] = 1;
            }
            else {
                R[u[j]].push_back(v[j]);
            }
        }
        for (int j = 1; j <= n; j += 1) {
            if (R[j].empty() or (a[j] >> i) % 2) continue;
            int s = 0;
            for (int k : R[j]) if (k == j or ban[k]) s = 1;
            if (s) a[j] |= 1 << i;
            else for (int k : R[j]) a[k] |= 1 << i;
        }
    }
    for (int i = 1; i <= n; i += 1)
        cout << a[i] << " ";
}