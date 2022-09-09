#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, H;
        cin >> n >> H;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        sort(a.begin(), a.end(), greater<int>());
        int ans = H / (a[0] + a[1]) * 2;
        H %= (a[0] + a[1]);
        for (int i = 0; i < n; i += 1)
            if (H > 0) {
                H -= a[i];
                ans += 1;
            }
        cout << ans << "\n";
    }
    return 0;
}