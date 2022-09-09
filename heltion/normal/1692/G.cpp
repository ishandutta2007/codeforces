#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, k, ans = 0;
        cin >> n >> k;
        vector<int> a(n);
        for (int& ai : a) cin >> ai;
        for (int i = 0, j = 0; i < n; i += 1) {
            j = max(j, i);
            while (j + 1 < n and a[j + 1] * 2 > a[j]) j += 1;
            ans += j - i >= k;
        }
        cout << ans << "\n";
    }
}