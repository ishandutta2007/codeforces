#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    string s, t;
    cin >> s >> t;

    int ans = 0;
    int curr = 1;
    for (int i = 0; i < n; ++i) {
        curr = ((curr - 1) << 1) + (t[i] - s[i]) + 1;
        curr = min(curr, INF);
        ans += min(curr, k);
    }   

    cout << ans << '\n';
    return 0;
}