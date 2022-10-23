#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> x(n), t(n);
        for (int& xi : x) cin >> xi;
        for (int& ti : t) cin >> ti;
        double L = ranges::max(t), R = 2e8, ans = 0;
        for (int i = 0; i < 60; i += 1) {
            double M = (L + R) / 2;
            double l = -1 / 0., r = 1 / 0.;
            for (int j = 0; j < n; j += 1) {
                l = max(x[j] - (M - t[j]), l);
                r = min(x[j] + (M - t[j]), r);
            }
            if (l <= r) R = M;
            else L = M;
            ans = l;
        }
        cout << ans << "\n";
    }
}