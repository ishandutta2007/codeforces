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
            a[i] = abs(a[i]);
        }
        vector<int> cnt(101);
        for (int i = 0; i < n; ++i) {
            cnt[a[i]]++;
        }
        int ans = 0;
        for (int i = 1; i <= 100; ++i) {
            ans += min(2, cnt[i]);
        }
        if (cnt[0]) {
            ++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}