#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        vector<array<int, 4>> ans;
        int m = min_element(a.begin(), a.end()) - a.begin();
        for (int i = 0; i < n; i++) {
            if (a[i] != a[m] + abs(i - m)) {
                ans.push_back({i + 1, m + 1, a[m] + abs(i - m), a[m]});
            }
        }

        cout << ans.size() << '\n';
        for (auto &v : ans) {
            for (int x : v) cout << x << ' ';
            cout << '\n';
        }
    }
}