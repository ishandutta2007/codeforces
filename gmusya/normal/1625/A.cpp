#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            int ones = 0, zeros = 0;
            for (int j = 0; j < n; ++j) {
                if (a[j] & (1 << i)) {
                    ++ones;
                } else {
                    ++zeros;
                }
            }
            if (ones >= zeros) {
                ans += (1 << i);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}