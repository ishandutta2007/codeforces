#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        vector<int> a(4);
        for (int& ai : a) cin >> ai;
        int ans = 0;
        for (int ai : a) ans += ai > a[0];
        cout << ans << "\n";
    }
}