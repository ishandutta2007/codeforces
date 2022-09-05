#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string op;
    int n, h;
    cin >> op >> n >> h;
    if (op == "Bob") cout << n << "\n", exit(0);
    double ans = n, pw = 1, pw2 = 1;
    for (int i = 1; i <= h; i++) {
        pw /= 2, pw2 *= 2;
        double t = 1;
        for (int j = 1; j <= n; j++) {
            ans += (n - j) * pw * t * 0.5 * (pw2 - j) / (pw2 - 1);
            t *= 1 - pw;
        }
    }
    cout << setprecision(10) << fixed << ans << endl;
    return 0;
}