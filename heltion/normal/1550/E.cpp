#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<int>> sum(k + 1, vector<int>(n));
    for (int i = 0; i < n; i += 1) {
        if (isalpha(s[i])) sum[s[i] - 'a'][i] += 1;
        else sum[k][i] += 1;
        if (i) for (int j = 0; j <= k; j += 1) sum[j][i] += sum[j][i - 1];
    }
    int L = 0, R = n / k;
    while (L < R) {
        int M = (L + R + 1) >> 1;
        vector<vector<int>> nxt(k, vector<int>(n, n));
        for (int i = n - M; i >= 0; i -= 1)
            for (int j = 0; j < k; j += 1) {
                nxt[j][i] = nxt[j][i + 1];
                int s = sum[j][i + M - 1] + sum[k][i + M - 1];
                if (i) s -= sum[j][i - 1] + sum[k][i - 1];
                if (s == M) nxt[j][i] = i;
            }
        vector<int> dp(1 << k, n);
        dp[0] = -1;
        for (int i = 1; i < (1 << k); i += 1)
            for (int j = 0; j < k; j += 1)
                if (dp[i ^ (1 << j)] + 1 < n)
                    dp[i] = min(dp[i], nxt[j][dp[i ^ (1 << j)] + 1] + M - 1);
        if (dp.back() < n) L = M;
        else R = M - 1;
    }
    cout << L;
    return 0;
}