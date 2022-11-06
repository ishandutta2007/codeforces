#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int mod = 1000000007;

int dp[2][1<<20];

int main() {
  int n;
  scanf("%d", &n);

  int now = 0, prev = 1;

  memset(dp[prev], 0, sizeof(dp[prev]));

  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    dp[prev][v]++;
  }

  for (int nr = 0; nr <= 19; nr++) {
    memset(dp[now], 0, sizeof(dp[now]));

    for (int s = 0; s < (1<<20); s++) {
      dp[now][s] += dp[prev][s];
      if (s & (1<<nr))
	dp[now][s ^ (1<<nr)] += dp[prev][s];
    }

    swap(now, prev);
  }

  vector<int> p2(n+1);

  p2[0] = 1;
  for (int i = 1; i <= n; i++) {
    p2[i] = p2[i-1] + p2[i-1];
    if (p2[i] >= mod)
      p2[i] -= mod;
  }

  int ret = 0;

  for (int s = 0; s < (1<<20); s++) {
    int v = dp[prev][s];
    int v2 = p2[v] - 1;
    if (v2 < 0) v2 += mod;

    if (__builtin_popcount(s)%2 == 0) {
      ret += v2;
      if (ret >= mod)
	ret -= mod;
    } else {
      ret -= v2;
      if (ret < 0)
	ret += mod;
    }
  }

  printf("%d\n", ret);

  return 0;
}