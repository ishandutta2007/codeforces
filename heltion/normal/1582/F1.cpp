#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL inf = 1E15;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector dp(512, 501);
    dp[0] = 0;
    for (int i = 0, a; i < n; i += 1) {
        cin >> a;
        vector nxt(dp);
        for (int i = 0; i < 512; i += 1)
            if (dp[i] <= a)
                nxt[i ^ a] = min(nxt[i ^ a], a);
        dp.swap(nxt);
    }
    int m = 0;
    for (int i = 0; i < 512; i += 1) m += dp[i] <= 500;
    cout << m << "\n";
    for (int i = 0; i < 512; i += 1) if (dp[i] <= 500) cout << i << " ";
    return 0;
}