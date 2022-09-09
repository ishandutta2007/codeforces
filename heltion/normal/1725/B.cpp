#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d;
    cin >> n >> d;
    vector<int> p(n);
    for (int& pi : p) cin >> pi;
    ranges::sort(p, greater<int>());
    int ans = 0;
    for (int i = 0, j = 0; i < n; i += 1) {
        j += d / p[i] + 1;
        if (j > n) break;
        ans += 1;
    }
    cout << ans;
}