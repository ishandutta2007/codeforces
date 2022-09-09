#include <bits/stdc++.h>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int& ai : a) cin >> ai;
        ranges::sort(a, greater<int>());
        partial_sum(a.begin(), a.end(), a.begin());
        for (int i = 0; i < q; i += 1) {
            int x;
            cin >> x;
            if (a.back() < x) cout << "-1\n";
            else cout << ranges::lower_bound(a, x) - a.begin() + 1 << "\n";
        }
    }
}