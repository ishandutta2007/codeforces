#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = n - 1;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int cur = 0;
                for (int k = 0; k < n; ++k) {
                    if (a[i] * (j - k) + a[j] * (k - i) != a[k] * (j - i)) {
                        ++cur;
                    }
                }
                ans = min(ans, cur);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}