#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <complex>
#include <map>
#include <numeric>
#include <set>
#include <utility>
#include <vector>
#include <cstring>

#define INF 1000000000
#define MAXN 5000

using namespace std;

typedef long long lint;

const int mod = 1e9+7;

int neq[MAXN+1][MAXN+1];
int dp[MAXN][MAXN], dpsum[MAXN][MAXN];
char seq[MAXN+1];

int main() {
  int n;
  scanf("%d %s", &n, seq);

  for (int i = 0; i <= n; ++i) neq[i][n] = 0;
  for (int j = 0; j <= n; ++j) neq[n][j] = 0;
  for (int i = n-1; i >= 0; --i)
    for (int j = n-1; j >= 0; --j)
      if (seq[i] == seq[j]) neq[i][j] = 1 + neq[i+1][j+1];
      else neq[i][j] = 0;
  
  for (int i = n-1; i >= 0; --i) {
    for (int j = n-1; j >= i; --j) {
      int &res = dp[i][j];

      if (j == n-1) res = 1;
      else if (seq[j+1] == '0') res = 0;
      else {
    int sizeij = j-i+1;
    res = 0;
    if (j+1+sizeij < n) res = (res + dpsum[j+1][j+1+sizeij]) % mod;

    if (j+1+sizeij-1 < n) {
      int neqab = neq[i][j+1];
      if (neqab < sizeij && seq[i+neqab] < seq[j+1+neqab]) {
        res = (res + dp[j+1][j+1+sizeij-1]) % mod;
      }
    }
      }

      dpsum[i][j] = dp[i][j];
      if (j+1 < n) dpsum[i][j] = (dpsum[i][j] + dpsum[i][j+1]) % mod;
    }
  }
  
  int ret = 0;
  for (int i = 0; i < n; ++i)
    ret = (ret + dp[0][i]) % mod;

  printf("%d\n", ret);
  
  return 0;
}