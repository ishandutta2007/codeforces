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

#define MAXN 105
#define MAXM 25

int n, m;

int s[MAXN];
char a[MAXM];
int t[MAXM];

int dp[1 << 20];
int bio[1 << 20];

int solve(int action, int mask) {
  if (action == m) return 0;
  if (bio[mask]) return dp[mask];

  bio[mask] = 1;
  int &ret = dp[mask];

  if (t[action] == 1) ret = -1000000000;
  if (t[action] == 2) ret = +1000000000;

  REP(i, m) {
    if (((mask >> i)  & 1) == 0) continue;
    if (t[action] == 1) ret = max(ret, solve(action + 1, mask ^ (1 << i)) + (a[action] == 'p' ? s[i] : 0));
    if (t[action] == 2) ret = min(ret, solve(action + 1, mask ^ (1 << i)) - (a[action] == 'p' ? s[i] : 0));
  }

  return ret;
}

int main(void)
{
  scanf("%d", &n);
  REP(i, n) scanf("%d", s + i);

  scanf("%d", &m);
  REP(i, m) scanf(" %c%d", a + i, t + i);

  sort(s, s + n);
  reverse(s, s + n);

  printf("%d\n", solve(0, (1 << m) - 1));

  return 0;
}