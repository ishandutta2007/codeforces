#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
vector < int > v;
int n, k;
inline int chk() {
    vector < int > a, b;
    a = v;
    int sum = 0;
    for (auto j : a) sum += j;
    if (sum > n) return 0;
    for (int i = 1; i < k; i++) {
        sum = 0;
        int now = 1;
        b.clear();
        for (int i = a.size(); i --> 0; ) {
            for (int j = 0; j < a[i]; j++) b.push_back(now);
            now++;
        }
        a = b;
        for (auto j : a) sum += j;
        if (sum > n) return 0;
    }
    return 1;
}
int ans;
inline void dfs(int x) {
    v.push_back(x);
    if (chk()) {
        ans++;
        dfs(x);
        v.pop_back();
        dfs(x + 1);
    }
    else v.pop_back();
}
int dp[75][2030];
int main() {
    scanf("%d%d", &n, &k);
    if (k == 1) {
        int *dp = ::dp[0];
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) dp[j] = (dp[j] + dp[j - i]) % mod;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) ans = (ans + dp[i]) % mod;
        return cout << ans << endl, 0;
    }
    else if (k == 2) {
        for (int i = 1; i <= 70; i++) dp[i][0] = 1; 
        for (int i = 1; i <= n; i++)
            for (int j = 70; j > 0; j--)
                for (int k = i * j; k <= n; k++) {
                    dp[j - 1][k] = (dp[j - 1][k] + dp[j][k - i * j]) % mod;
                }
        int ans = 0;
        for (int i = 1; i <= n; i++) ans = (ans + dp[0][i]) % mod;
        return cout << ans << endl, 0;
    }
    else {
        for (int i = 1; i <= n; i++) {
            v.push_back(i);
            if (chk()) dfs(i), ans++;
            v.pop_back();
        }
    }
    return cout << ans << endl, 0;
}