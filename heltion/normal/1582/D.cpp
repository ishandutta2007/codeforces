#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        if (n & 1) {
            if (a[1] + a[2] != 0) cout << a[1] + a[2] << " " << -a[0] << " " << -a[0] << " ";
            else if (a[0] + a[2] != 0) cout << -a[1] << " " << a[0] + a[2] << " " << -a[1] << " ";
            else cout << -a[2] << " " << -a[2] << " " << a[0] + a[1] << " ";
        }
        for (int i = (n & 1 ? 3 : 0); i < n; i += 2)
            cout << a[i + 1] << " " << -a[i] << " ";
        cout << "\n";
    }
    return 0;
}