#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        int ans = k;
        vector<int> sum(n + 1);
        for (int i = 0; i < n; i += 1)
            sum[i + 1] = sum[i] + (s[i] == 'W');
        for (int i = k; i <= n; i += 1)
            ans = min(ans, sum[i] - sum[i - k]);
        cout << ans << "\n";
    }
    return 0;   
}