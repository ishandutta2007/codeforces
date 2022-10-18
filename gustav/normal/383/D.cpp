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

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define MAXS 10005
#define MAXN 1005

int n;
int a[MAXN];
int dp[2][2 * MAXS];

const int mod = 1000000007;
int fmod(int a) { return a >= mod ? a - mod : a; }
int add(int a, int b) { return fmod(a + b); }

int main(void)
{
  scanf("%d", &n);
  REP(i, n) scanf("%d", &a[i]);

  int sol = 0;
  for (int i = n - 1; i >= 0; --i) {
    int I = i % 2;
    for (int j = -10000; j <= +10000; ++j) {
      int J = j + 10000;
      dp[I][J] = (j + a[i] == 0) + (j - a[i] == 0);
      if (J - a[i] >= 0  ) dp[I][J] = add(dp[I][J], dp[I ^ 1][J - a[i]]);
      if (J + a[i] <= 20000) dp[I][J] = add(dp[I][J], dp[I ^ 1][J + a[i]]);
    }
    sol = add(sol, dp[I][10000]);
    if (sol < 0) sol = sol + mod;
  }

  printf("%d\n", sol);

  return 0;
}