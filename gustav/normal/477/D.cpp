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
#define log(...) fprintf(stderr, ##__VA_ARGS__)

const int mod = 1000000007;
const int inf = 1000000;

#define MAX 5005

int lcp[MAX][MAX];
char b[MAX]; int n;


bool lte(int i, int j, int len) {
  if (lcp[i][j] >= len) 
    return true;
  return b[i + lcp[i][j]] < b[j + lcp[i][j]];
}


int dp2[MAX][MAX][2];
int steps(int pos, int len, bool good) {
  if (pos == -1) return 0;
  if (len == 0) return inf;

  int &ref = dp2[pos][len][good];
  if (ref >= 0) return ref;

  ref = steps(pos, len - 1, 1);

  if (pos + 1 < len)
    return ref;

  if (b[pos - len + 1] == '0')
    return ref;

  if (lte(pos - len + 1, pos + 1, len) || good)
    ref = min(ref, steps(pos - len, len, 0) + 1);

  return ref;
}

int dp[MAX][MAX][2];
int solve(int pos, int len, int good) {
  if (pos == -1) return 1;
  if (len == 0) return 0;

  int &ref = dp[pos][len][good];
  if (ref >= 0) return ref;

  ref = solve(pos, len - 1, 1);

  if (pos + 1 < len) 
    return ref;

  if (b[pos - len + 1] == '0')
    return ref;

  if (!lte(pos - len + 1, pos + 1, len) && !good)
    return ref;

  ref += solve(pos - len, len, 0);
  if (ref >= mod) ref -= mod;

  return ref;
}

int main(void)
{
  scanf("%s", b); n = strlen(b);

  for (int i = n - 1; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) {
      if (b[i] == b[j])
        lcp[i][j] = 1 + lcp[i + 1][j + 1];
      else
        lcp[i][j] = 0;
    }
  }

  memset(dp, -1, sizeof dp);
  memset(dp2, -1, sizeof dp2);
  
  int ways = 0;

  for (int len = 1; len <= n; ++len) 
    if (b[n - len] != '0')
      ways = (ways + solve(n - 1 - len, len, 0)) % mod;

  int best = 1 << 30;

  for (int len = 1; len <= min(n, 30); ++len) {
    if (b[n - len] != '1') continue;
    int num = 0;
    REP(i, len) num = num * 2 + b[n - len + i] - '0';
    if (steps(n - 1 - len, len, 0) < inf) {
      best = min(best, num + steps(n - 1 - len, len, 0) + 1);
    }
  }

  if (best != (1 << 30)) {
    printf("%d\n", ways);
    printf("%d\n", best % mod);
    exit(0);
  }

  for (int len = 1; len <= n; ++len) {
    if (b[n - len] != '1') continue;
    if (steps(n - 1 - len, len, 0) < inf) {
      printf("%d\n", ways);
      int num = 0;
      REP(i, len) {
        num *= 2;
        num += b[n - len + i] - '0';
        num %= mod;
      }
      printf("%d\n", (num + steps(n - 1 - len, len, 0) + 1) % mod);
      exit(0);
    }
  }

  return 0;
}