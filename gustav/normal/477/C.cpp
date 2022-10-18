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

#define MAXS 2005
#define MAXP 505

char s[MAXS]; int n;
char p[MAXP]; int m;

int sol[MAXS];
int f[MAXP];

vector< vector< vector< int > > > dp; // dp[pos][match][k]

int solve(int pos, int match, int k) {
  if (k == 0) return 0;
  if (match == m)
    return solve(pos, 0, k - 1);
  if (pos == n) return 1000000;

  int &ret = dp[pos][match][k];
  if (ret >= 0) return ret;

  ret = 1000000;

  if (s[pos] == p[match])
    ret = min(ret, solve(pos + 1, match + 1, k));

  // brisi znak
  ret = min(ret, solve(pos + 1, match, k) + 1);
  ret = min(ret, solve(pos + 1, 0, k));

  // mijenjaj match
  if (match > 0)
    ret = min(ret, solve(pos, f[match - 1] + 1, k));

  return ret;
}

int main(void)
{
  scanf("%s", s); n = strlen(s);
  scanf("%s", p); m = strlen(p);

  if (n < m) {
    REP(i, n + 1)
      printf("0 ");
    puts("");
    exit(0);
  }

  dp.resize(MAXS);
  REP(i, MAXS) {
    dp[i].resize(m + 1);
    REP(j, m + 1)
      dp[i][j].resize(n / m + 1, -1);
  }

  f[0] = -1;
  FOR(i, 1, m) {
    f[i] = f[i - 1];
    while (f[i] != -1 && p[i] != p[f[i] + 1])
      f[i] = f[f[i]];
    if (p[i] == p[f[i] + 1]) ++f[i];
  }

  REP(k, n / m + 1) {
    int B = solve(0, 0, k);
    if (B > n) continue;
    FOR(i, B, B + n - B - k * m + 1) sol[i] = k;
  }

  REP(i, n + 1)
    printf("%d ", sol[i]);

  puts("");

  return 0;
}