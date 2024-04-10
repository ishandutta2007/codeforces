#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 7;
const int MOD = 1000 * 1000 * 1000 + 7;
int mod(int n) {
    return (n % MOD + MOD) % MOD;
}   
int a[N];
vector <int> g[N];
int sum[N];
int w[N];
int cnt[N];
int dp[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int p; cin >> p; --p;
        g[p].push_back(i);
    }   
    int SUM = 0;
    for (int i = 0; i < n; ++i) SUM += a[i];
    for (int i = n - 1; i >= 0; --i) {
        sum[i] = a[i];
        for (int v : g[i]) {
            sum[i] += sum[v];
        }   
    }   
    for (int i = 0; i < n; ++i) {
        w[i] = SUM / __gcd(SUM, sum[i]);
        if (w[i] < N) {
            ++cnt[w[i]];
        }
    }   
    for (int i = N - 1; i >= 0; --i) {
        if (cnt[i]) {
            for (int j = i * 2; j < N; j += i) {
                cnt[j] += cnt[i];
            }   
        }   
    }
    int ans = 0;
    for (int i = n; i >= 1; --i) {
        dp[i] = (SUM % i == 0) && cnt[i] == i;        
        if (!dp[i]) continue;
        for (int j = i * 2; j <= n; j += i) {
            dp[i] = mod(dp[i] + dp[j]);
        }   
        ans = mod(ans + dp[i]);
    }   
    cout << dp[1] << '\n';
}