#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

signed main() {
    int tcs;
    cin >> tcs;
    while (tcs--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& i : a) cin >> i;
        sort(a.begin(), a.end());

        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (a[i] - a[i - 1] > 1) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}