#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int& i : a) cin >> i;
        for (int& i : b) cin >> i;

        int ma = *min_element(a.begin(), a.end());
        int mb = *min_element(b.begin(), b.end());
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += max(a[i] - ma, b[i] - mb);
        }

        cout << ans << '\n';
    }

    return 0;
}