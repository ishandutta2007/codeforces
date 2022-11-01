#include <algorithm>
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
        if (a[0] != n && a[n - 1] != n) {
            cout << -1 << '\n';
        } else {
            reverse(a.begin(), a.end());
            for (int x : a) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}