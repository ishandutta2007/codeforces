#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100001;
const int MOD = 1000 * 1000 * 1000 + 7;
int mod(int n) {
    return (n % MOD + MOD) % MOD;
}   
int fp(int n, int p) {
    int ans = 1;
    int c = n;
    for (int i = 0; (1ll << i) <= p; ++i) {
        if ((p >> i) & 1) ans = mod(ans * c);
        c = mod(c * c);
    }   
    return ans;
}   
int mdiv(int a, int b) {
    return mod(a * fp(b, MOD - 2));
}   
vector <int> d[N];
int dp[N];
int cnt[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    for (int i = 1; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            d[j].push_back(i);
        }   
    }   
    for (int i = 0; i < N; ++i) {
        reverse(d[i].begin(), d[i].end());
    }   

    int n;
    cin >> n;
    dp[1] = 0;
    int ans = 0;
    for (int i = 2; i <= n; ++i) {
        int sum = 0;
        for (int t : d[i]) {
            cnt[t] = n / t;
            for (int e : d[i]) {
                if (e > t && e % t == 0) {
                    cnt[t] -= cnt[e];
                }   
            }   
            if (t < i) {  
                sum = mod(sum + cnt[t] * dp[t]);
            }
        }   
        int c = cnt[i];
        dp[i] = mdiv(sum + n, n - c);
        ans = mod(ans + dp[i]);
    }
    cout << mdiv(ans + n, n) << '\n';
}