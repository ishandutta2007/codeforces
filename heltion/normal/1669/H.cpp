#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, k;
        cin >> n >> k;
        vector<int> c(31);
        for (int i = 0, a; i < n; i += 1) {
            cin >> a;
            for (int j = 0; j <= 30; j += 1)
                c[j] += (a >> j) & 1;
        }
        int ans = 0;
        for (int i = 30; i >= 0; i -= 1) {
            int h = n - c[i];
            ans *= 2;
            if (h <= k) {
                ans += 1;
                k -= h;
            }
        }
        cout << ans << "\n";
    }
}