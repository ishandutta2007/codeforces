#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m;
        cin >> n >> m;
        vector<pair<LL, LL>> p(m);
        for (auto& [x, w] : p) cin >> x >> w;
        vector<int> v(m);
        for (int i = 0; i < m; i += 1) v[i] = i;
        sort(v.begin(), v.end(), [&](int x, int y){
            return p[x].second < p[y].second;
        });
        v.resize(2 * n);
        sort(v.begin(), v.end(), [&](int x, int y){
            return p[x].first < p[y].first;
        });
        LL ans = 0;
        for (int i : v) ans += p[i].second;
        cout << ans << "\n";
        for (int i = 0; i < n; i += 1) cout << v[i] + 1 << " " << v[2 * n - 1 - i] + 1 << "\n";
    }
    return 0;
}