#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        LL s = 0, m = LLONG_MIN;
        for (int i = 0; i < n; i += 1) {
            LL a;
            cin >> a;
            s += a;
            m = max(m, a);
        }
        cout << m + 1.0 * (s - m) / (n - 1) << "\n";
    }
    return 0;
}