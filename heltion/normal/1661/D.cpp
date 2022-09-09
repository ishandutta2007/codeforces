#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<LL> b(n);
    vector<LL> p(n), q(n);
    for (LL& bi : b) cin >> bi;
    ranges::reverse(b);
    LL ans = 0;
    for (int i = 0; i < n; i += 1) {
        LL x = max(b[i] - (p[i] * i + q[i]), 0LL);
        LL y = min(k, n - i);
        LL z = (x + y - 1) / y;
        ans += z;
        p[i] += -z;
        q[i] += (y + i) * z;
        if (i + y < n) {
            p[i + y] -= -z;
            q[i + y] -= (y + i) * z;
        }
        if (i + 1 < n) {
            p[i + 1] += p[i];
            q[i + 1] += q[i];
        }
    }
    cout << ans;
    return 0;
}