#include <bits/stdc++.h>
using namespace std;

int n, m, f[8];

int main() {
    auto query = [&](int d) {
        cout << "? " << (200 + d - 1) / d * 200 << endl;
        for (int i = 1; i <= 200; i += d) {
            for (int j = 1; j <= 200; j++) {
                cout << i << " " << j << " ";
            }
        }
        cout << endl;
        int x; cin >> x; return x;
    };
    f[0] = query(1);
    int l = 1, r = 7, k = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        f[mid] = query(1 << mid);
        if (f[0] == f[mid] * (1 << mid)) l = (k = mid) + 1;
        else r = mid - 1;
    }
    int h = abs(2 * f[k + 1] - f[k]);
    cout << "! " << 2 * (h + f[0] / h - 2) << endl;
    return 0;
}