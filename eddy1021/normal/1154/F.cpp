#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr int N = 2048;
LL n, m, k, a[202020], bst[N], sum[N], dp[N];
int main(){
  scanf("%lld%lld%lld", &n, &m, &k);
  for (int i=1; i<=n; ++i) {
    scanf("%lld", &a[i]);
  }
  for (int i=0; i<m; ++i) {
    LL xi, yi; scanf("%lld%lld", &xi, &yi);
    if (xi > k) continue;
    bst[xi] = max(bst[xi], yi);
  }
  sort(a+1, a+n+1);
  n = k;
  for (int i=1; i<=n; ++i) {
    sum[i] = sum[i-1] + a[i];
  }
  auto cost = [&](int lb, int rb) {
    int len = rb - lb + 1;
    len -= bst[len];
    return sum[rb] - sum[rb - len];
  };
  for (int i=1; i<=n; ++i) {
    dp[i] = 1e16;
    for (int j=1; j<=i; ++j) {
      dp[i] = min(dp[i],
                  dp[i-j] + cost(i-j+1, i));
    }
  }
  printf("%lld\n", dp[n]);
}