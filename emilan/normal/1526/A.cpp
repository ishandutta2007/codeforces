#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(2 * n);
        for (int &x : a) cin >> x;

        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ' << a[i + n] << ' ';
        }
        cout << '\n';
    }
}