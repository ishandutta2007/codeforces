#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, ans = 0;
        cin >> n;
        vector<LL> p(n + 1), l(n + 1), r(n + 1), a(n + 1);
        for (int i = 2; i <= n; i += 1) cin >> p[i];
        for (int i = 1; i <= n; i += 1) cin >> l[i] >> r[i];
        for (int i = n; i >= 1; i -= 1) {
            if (a[i] < l[i]) {
                ans += 1;
                a[i] = r[i];
            }
            a[p[i]] += min(a[i], r[i]);
        }
        cout << ans << "\n";
    }
}