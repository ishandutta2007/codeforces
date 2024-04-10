#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& ai : a) cin >> ai;
    int ans = INT_MAX;
    for (int i = 0; i + 1 < n; i += 1) {
        int pans = max({(a[i] + a[i + 1] + 2) / 3, (a[i] + 1) / 2, (a[i + 1] + 1) / 2});
        ans = min(ans, pans);
    }
    for (int i = 0; i + 2 < n; i += 1) {
        int pans = min(a[i], a[i + 2]) + (abs(a[i] - a[i + 2]) + 1) / 2;
        ans = min(ans, pans);
    }
    ranges::sort(a);
    ans = min(ans, (a[0] + 1) / 2 + (a[1] + 1) / 2);
    cout << ans << "\n";
}