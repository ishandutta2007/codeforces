#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long A = a[0], B = 0;
        for (int i = 1; i < n; i++) {
            if (A + B < a[i]) {
                B = a[i] - A;
            } else {
                A = a[i] - B;
            }
        }
        long long res = a[0] + B;
        if (A < 0) {
            res -= 2 * A;
        }
        cout << res << "\n";
    }
}