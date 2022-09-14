#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> x(n), y(n), z(n);
        for (int& xi : x) cin >> xi;
        for (int& yi : y) cin >> yi;
        for (int i = 0; i < n; i += 1)
            z[i] = y[i] - x[i];
        ranges::sort(z);
        int ans = 0;
        for (int i = 0, j = n - 1; i < j; i += 1, j -= 1) {
            while (i < j and z[i] + z[j] < 0) i += 1;
            if (i < j) ans += 1;
        }
        cout << ans << "\n";
    }
}