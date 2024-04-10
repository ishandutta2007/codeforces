#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    for (cin >> T; T; T -= 1) {
        int n, k, ans = 0;
        cin >> n >> k;
        for (int i = 1, p; i <= n; i += 1) {
            cin >> p;
            ans += p > k and i <= k;
        }
        cout << ans << "\n";
    }
}