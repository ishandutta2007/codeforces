#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> p(n + 1), s(n + 1), v(n + 1);
        v[0] = 1;
        for (int i = 1; i <= n; i += 1) {
            cin >> p[i];
            if (p[i] == i) p[i] = 0;
            s[p[i]] += 1;
        }
        vector<vector<int>> ans;
        for (int i = 1; i <= n; i += 1)
            if (s[i] == 0) {
                ans.emplace_back();
                for (int j = i; not v[j]; j = p[j]) {
                    v[j] = 1;
                    ans.back().push_back(j);
                }
            }
        cout << ans.size() << "\n";
        for (auto& ansi : ans) {
            ranges::reverse(ansi);
            cout << ansi.size() << "\n";
            for (int x : ansi) cout << x << " ";
            cout << "\n";
        }
        cout << "\n";
    }
}