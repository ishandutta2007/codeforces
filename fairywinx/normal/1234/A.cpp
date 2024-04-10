#include <bits/stdc++.h>

using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int c;
            cin >> c;
            sum += c;
        }
        cout << (sum + n - 1) / n << '\n';
    }
}