#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i += 1)
        cin >> a[i];
    LL ans = (LL)n * (n + 1) / 2;
    for (int i = 1; i < n; i += 1)
        if (a[i] != a[i + 1])
            ans += (LL)i * (n - i);
    for (int i = 0, x, y; i < m; i += 1) {
        cin >> x >> y;
        if (x > 1 and a[x] != a[x - 1])
            ans -= (LL)(x - 1) * (n - x + 1);
        if (x < n and a[x] != a[x + 1])
            ans -= (LL)x * (n - x);
        a[x] = y; 
        if (x > 1 and a[x] != a[x - 1])
            ans += (LL)(x - 1) * (n - x + 1);
        if (x < n and a[x] != a[x + 1])
            ans += (LL)x * (n - x);
        cout << ans << "\n";
    }
}