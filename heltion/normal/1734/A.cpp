#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& ai: a) cin >> ai;
        ranges::sort(a);
        int ans = a[2] - a[0];
        for (int i = 3; i < n; i += 1)
            ans = min(ans, a[i] - a[i - 2]);
        cout << ans << "\n";
    }
}