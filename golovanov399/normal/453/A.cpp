#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> m >> n;
    double ans = 0;
    for (int i = 1; i <= m; ++i) {
        ans += i * (pow(1.0 * i / m, n) - pow(1.0 * (i - 1) / m, n));
    }
    cout << setprecision(10) << fixed;
    cout << ans << "\n";
}