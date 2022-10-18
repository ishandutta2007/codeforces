#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <stack>
#include <queue>
#include <vector>

#include <bitset>

#include <string>

#include <algorithm>
#include <functional>

#include <iostream>
#include <sstream>

using namespace std;
typedef long long llint;

#define pb push_back

#define MAX 1005
const int mod = 1000000007;

int mul(int a, int b) { return (llint)a * b % mod; }
int add(int a, int b) { return (a + b) % mod; }

int t, n, k;

int dp[MAX][MAX];
int f[MAX];

int calc(int k, int m) {
  if (k == 0) return (m == 0);
  if (m < 0) return 0;

  int &ref = dp[k][m];
  if (ref >= 0) return ref;

  return ref = add(calc(k, m - k), calc(k - 1, m - k + 1));
}

int choose[MAX][MAX];
int sol[MAX][MAX];

int main(void)
{
  f[0] = 1;
  for (int i = 1; i < MAX; ++i)
    f[i] = mul(f[i - 1], i);

  for (int n = 0; n < MAX; ++n) {
    for (int k = 0; k < MAX; ++k) {
      if (n < k) {
        choose[n][k] = 0;
        continue;
      }
      if (n == k || k == 0) {
        choose[n][k] = 1;
        continue;
      }
      choose[n][k] = add(choose[n - 1][k - 1], choose[n - 1][k]);
    }
  }

  memset(dp, -1, sizeof dp);

  for (int k = 1; k < MAX; ++k) {
    for (int n = k * (k + 1) / 2; n < MAX; ++n) {
      for (int w = 0; w <= n - k; ++w) {
        sol[k][n] = add(sol[k][n], mul(calc(k, n - k - w), choose[w + k][k]));
      }
    }
  }

  scanf("%d", &t);

  while (t--) {
    scanf("%d%d", &n, &k);
    printf("%d\n", mul(sol[k][n], f[k]));
  }

  return 0;
}