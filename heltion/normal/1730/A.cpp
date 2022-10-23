#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, c, ans = 0;
        cin >> n >> c;
        map<int, int> mp;
        for (int i = 0, a; i < n; i += 1) {
            cin >> a;
            mp[a] += 1;
        }
        for (auto [x, y] : mp)
            ans += min(c, y);
        cout << ans << "\n";
    }
}