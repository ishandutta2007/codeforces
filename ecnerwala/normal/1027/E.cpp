#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
const int MAXN = 600;
int N, K;
ll dp[MAXN];
ll cnt[MAXN];
int main() {
 cin >> N >> K;
 for (int k = N; k >= 1; k--) {
  dp[1]=1;
  for (int z=1; z < N; z++) {
   ll t = dp[1];
   for (int i = k; i > 1; i--) t+=dp[i], dp[i]=dp[i-1];
   dp[1] = t % MOD;
  }
  ll c = 0;
  for (int i = 1; i <= k; i++) c += dp[i], dp[i] = 0;
  cnt[k] = c % MOD;
  if (k < N) cnt[k+1] = (cnt[k+1]-cnt[k] + MOD) % MOD;
 }
 int res = 0;
 for (int l = 1; l <= N; l++) {
  for (int r = 1; r <= N; r++) {
   if (l * r < K) res = (res + 2*cnt[l] * cnt[r]) % MOD;
  }
 }
 cout << res << '\n';
}