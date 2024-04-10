#include <algorithm>
#include <iostream>
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
        vector<int> a(n);
        for (int& i : a) cin >> i;
        sort(a.begin(), a.end());

        int mx = 0;
        for (int i = 2; i <= 2 * n; i++) {
            int l = 0, r = n - 1, cnt = 0;
            while (l < r) {
                int sum = a[l] + a[r];
                if (sum > i) r--;
                else if (sum < i) l++;
                else cnt++, l++, r--;
            }
            mx = max(mx, cnt);
        }

        cout << mx << '\n';
    }

    return 0;
}