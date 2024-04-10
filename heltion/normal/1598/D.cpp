#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<LL> ca(n + 1), cb(n + 1);
        vector<vector<int>> pa(n + 1);
        for (int i = 0, a, b; i < n; i += 1) {
            cin >> a >> b;
            ca[a] += 1;
            cb[b] += 1;
            pa[a].push_back(b);
        }
        LL ans = 0;
        for (LL i = 1, x = 0, y = 0; i <= n; i += 1) {
            ans += y * ca[i];
            y += x * ca[i];
            x += ca[i];
        }
        for (int i = 1; i <= n; i += 1) ans += ca[i] * (ca[i] - 1) * (ca[i] - 2) / 6;
        for (int i = 1; i <= n; i += 1) {
            ans += ca[i] * (ca[i] - 1) / 2 * ((n - ca[i]) + 2);
            for (int j : pa[i]) ans -= cb[j] * (ca[i] - 1);
        }
        cout << ans << "\n";
    }
    return 0;
}