#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <map>
#include <unordered_set>
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

const int MAXN = 1000005;

char t[MAXN]; int m;
char s[MAXN]; int n;

int f[MAXN];
int start[MAXN];

void precalc() {
  f[0] = -1;
  for (int i = 1; i < m; ++i) {
    f[i] = f[i - 1];

    while (f[i] != -1 && t[f[i] + 1] != t[i])
      f[i] = f[f[i]];

    if (t[f[i] + 1] == t[i])
      ++f[i];
  }
}

void kmp() {
  for (int i = 0, j = -1; i < n; ++i) {
    while (j != -1 && t[j + 1] != s[i])
      j = f[j];

    if (t[j + 1] == s[i])
      ++j;

    if (j == m - 1) {
      j = f[j];
      start[i - m + 1] = 1;
    }
  }
}

const int mod = 1000000007;

int add(int a, int b) { return (a + b) % mod; }

int dp[MAXN];
int sum[MAXN];

int main(void)
{
  scanf("%s", s); n = strlen(s);
  scanf("%s", t); m = strlen(t);

  precalc();
  kmp();

  int cnxt = -1;
  sum[n] = 1;

  dp[n] = 1;

  for (int i = n - 1; i >= 0; --i) {
    if (start[i]) cnxt = i;

    dp[i] = dp[i + 1];

    if (cnxt != -1) 
      dp[i] = add(dp[i], sum[cnxt + m]);

    sum[i] = add(dp[i], sum[i + 1]);
  }

  printf("%d\n", add(dp[0], mod - 1));

  return 0;
}