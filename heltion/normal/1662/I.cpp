#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<LL> p(n), s(n), x(m);
    for (int i = 0; i < n; i += 1) {
        cin >> p[i];
        s[i] = p[i];
        if (i) s[i] += s[i - 1];
    }
    for (LL& xi : x) {
        cin >> xi;
        xi *= 2;
    }
    sort(x.begin(), x.end());
    LL ans = 0;
    for (int i = 0, lx = -1, rx = 0; i <= (n - 1) * 200; i += 1) {
        while (lx + 1 < m and x[lx + 1] <= i) lx += 1;
        while (rx < m and x[rx] < i) rx += 1;
        LL Lx = ~lx ? x[lx] : INT_MIN, Rx = rx < m ? x[rx] : INT_MAX;
        LL L = (i + Lx) / 2 + 1, R = (i + Rx + 1) / 2 - 1;
        int l = max(0LL, (L + 199) / 200), r = min(n - 1LL, R / 200);
        if (l <= r) {
            LL pans = s[r];
            if (l) pans -= s[l - 1];
            ans = max(ans, pans);
        }
    }
    cout << ans;
}