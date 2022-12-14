#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;

        bool bad = false;
        int l1 = max(a[1] - b[0], 0);
        int r1 = a[1];
        int l = l1;
        for (int i = 1; i < n - 1; i++) {
            l += a[i + 1] - b[i];
            r1 = min(l1 + (a[i + 1] - l), r1);

            if (l < 0) {
                l1 = min(l1 - l, r1);
                l = 0;
            } else if (l > a[i + 1]) {
                bad = true;
                break;
            }
        }

        if (bad) {
            cout << "No\n";
            continue;
        }

        int cost = a[1] - l1;
        int l0 = max(a[0] - (b[0] - cost), 0);

        if (b[n - 1] >= l + l0) cout << "yEs\n";
        else cout << "nO\n";
    }
}