#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

/// #define int ll

int M;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

const int N = (int) 4e6 + 7;
int n, dp[N], sum, p[N];

void push(int i) {
  for (int d = 1; i * d <= n; d++) {
    int l = max(i + 1, i * d), r = min(n, (i + 1) * d - 1);
    if (l <= r) {
      p[l] = add(p[l], dp[i]);
      p[r + 1] = add(p[r + 1],- dp[i]);
    }
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);


  //n = 42;
  //M = 998244353;
  cin >> n >> M;
  dp[1] = 1;
  sum = 1;
  push(1);
  for (int i = 2; i <= n; i++) {
    p[i] = add(p[i], p[i - 1]);
    dp[i] = add(dp[i], p[i]);
    dp[i] = add(dp[i], sum);
    sum = add(sum, dp[i]);
    push(i);
  }
  cout << dp[n] << "\n";
	//assert(dp[n] == 793019428);
	return 0;
}