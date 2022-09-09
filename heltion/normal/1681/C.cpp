#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int& ai : a) cin >> ai;
        for (int& bi : b) cin >> bi;
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; i += 1)
            for (int j = 0; j + 1 < n; j += 1) {
                if (a[j] > a[j + 1] or b[j] > b[j + 1]) {
                    ans.emplace_back(j, j + 1);
                    swap(a[j], a[j + 1]);
                    swap(b[j], b[j + 1]);
                }
            }
        if (not ranges::is_sorted(a) or not ranges::is_sorted(b))
            cout << "-1\n";
        else {
            cout << ans.size() << "\n";
            for (auto [i, j] : ans) cout << i + 1 << " " << j + 1 << "\n";
        }
    }
    return 0;
}