#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int t = 1;
    int ans = 0;
    int sum = 0;
    while (sum < n) {
        ++ans;
        sum += t;
        t <<= 1;
    }

    cout << ans << '\n';
    return 0;
}