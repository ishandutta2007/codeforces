#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        vector<int> a(n), b(n - 1);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;

        int days = 0, x = 0, ans = 1e9;
        for (int i = 0; i < n; i++) {
            int c_days = max((c - x + a[i] - 1) / a[i], 0);
            ans = min(days + c_days, ans);

            if (i < n - 1) {
                int b_days = max((b[i] - x + a[i] - 1) / a[i], 0);
                if (days + b_days + 1 >= ans) break;

                days += b_days + 1;
                x += b_days * a[i] - b[i];
            }
        }

        cout << ans << '\n';
    }
}