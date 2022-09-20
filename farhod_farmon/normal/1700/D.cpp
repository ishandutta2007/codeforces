#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0) {
            a[i] += a[i - 1];
        }
        b[i] = (a[i] - 1) / (i + 1) + 1;
        if (i > 0) {
            b[i] = max(b[i], b[i - 1]);
        }
    }

    int q;
    cin >> q;
    while (q--) {
        long long t;
        cin >> t;
        long long res = (a[n - 1] - 1) / t + 1;
        if (res > n || b[res - 1] > t) {
            cout << -1 << "\n";
        } else {
            cout << res << "\n";
        }
    }
}