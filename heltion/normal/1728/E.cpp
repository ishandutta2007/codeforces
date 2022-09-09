#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL exgcd(LL a, LL b, LL& x, LL& y){
    if(not b) return x = 1, y = 0, a;
    LL d = exgcd(b, a % b, x, y), t = x;
    return x = y, y = t - a / b * y, d;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<LL> a(n), b(n), d;
    LL sum = 0;
    for (int i = 0; i < n; i += 1) {
        cin >> a[i] >> b[i];
        sum += b[i];
        d.push_back(a[i] - b[i]);
    }
    ranges::sort(d, greater<int>());
    vector<LL> ans(n + 1, sum);
    for (int i = 0; i < n; i += 1)
        ans[i + 1] = ans[i] + d[i];
    LL mx = ranges::max_element(ans) - ans.begin();
    int m;
    cin >> m;
    for (int i = 0; i < m; i += 1) {
        LL x, y;
        cin >> x >> y;
        LL a, b, d = exgcd(x, y, a, b);
        if (n % d) {
            cout << "-1\n";
            continue;
        }
        LL kx = x / d, ky = y / d;
        LL L = (a * (n / d) % ky + ky) % ky;
        if (L * x > n) {
            cout << "-1\n";
            continue;
        }
        LL R = (n - L * x) / lcm(x, y) * ky + L;
        if (R * x <= mx) cout << ans[R * x] << "\n";
        else if (L * x >= mx) cout << ans[L * x] << "\n";
        else {
            LL mR = R - (R * x - mx) / x / ky * ky;
            LL mL = L + (mx - L * x) / x / ky * ky;
            cout << max(ans[mL * x], ans[mR * x]) << "\n";
        }
    }
}