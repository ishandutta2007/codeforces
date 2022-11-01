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
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n; ++i) {
            cnt0 += (a[i] == 0);
            cnt1 += (a[i] == 1);
        }
        cout << (1ll << cnt0) * 1ll * cnt1 << '\n';
    }
    return 0;
}