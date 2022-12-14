#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> ans;
        for (int i = (k + 1) / 2; i <= n; i++) {
            if (i != k) ans.push_back(i);
        }
        cout << ans.size() << '\n';
        for (int i : ans) cout << i << ' ';
        cout << '\n';
    }
}