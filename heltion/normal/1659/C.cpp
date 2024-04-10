#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, a, b;
        cin >> n >> a >> b;
        vector<LL> x(n + 1), sx(n + 1);
        for (int i = 1; i <= n; i += 1) {
            cin >> x[i];
            sx[i] = sx[i - 1] + x[i];
        }
        LL ans = LLONG_MAX;
        for (int i = 0; i <= n; i += 1) {
            LL pans = x[i] * (a + b) + ((sx[n] - sx[i]) - x[i] * (n - i)) * b;
            ans = min(ans, pans);
        }
        cout << ans << "\n";
    }
}