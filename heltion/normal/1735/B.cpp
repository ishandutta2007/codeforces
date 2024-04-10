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
        for (int& ai : a) cin >> ai;
        ranges::sort(a);
        int ans = 0;
        for (int ai : a)
            ans += (ai - 1) / (a[0] * 2 - 1);
        cout << ans << "\n";
    }
}