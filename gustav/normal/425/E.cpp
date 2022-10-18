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

const int mod = 1000000007;

#define MAX 505

int n, k;
int dp[MAX][MAX];
int p2[MAX * MAX];

int add(int a, int b) { return (a + b) % mod; }
int sub(int a, int b) { return add(a, mod - b); }
int mul(int a, int b) { return ((llint)a * b) % mod; }

int main(void)
{
  scanf("%d%d", &n, &k);

  p2[0] = 1;
  for (int i = 1; i < MAX * MAX; ++i)
    p2[i] = mul(p2[i - 1], 2);

  for (int x = 0; x <= n; ++x)
    dp[x][0] = p2[x * (n - x)];

  for (int i = 1; i <= k; ++i) {
    dp[n][i] = 0;
    for (int x = n - 1; x >= 0; --x) {
      dp[x][i] = 0;
      for (int y = x + 1; y <= n; ++y)
        dp[x][i] = add(dp[x][i], mul(p2[x * (y - x - 1)], 
                   mul(sub(p2[y], p2[x]), dp[y][i - 1])));
    }
  }
 
  printf("%d\n", dp[0][k]);

  return 0;
}