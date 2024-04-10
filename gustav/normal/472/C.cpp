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

#define MAXN 100005

int n;
int p[MAXN];
string f[MAXN][2];

int dp[2][MAXN];

bool solve(int last, int pos) {
  if (pos == n) return true;

  int &ref = dp[last][pos];
  if (ref >= 0) return ref;

  ref = 0;

  if (f[p[pos - 1]][last] < f[p[pos]][0] && solve(0, pos + 1))
    ref = true;
  
  if (f[p[pos - 1]][last] < f[p[pos]][1] && solve(1, pos + 1))
    ref = true;

  return ref;
}

int main(void)
{
  cin >> n;
  REP(i, n) cin >> f[i][0] >> f[i][1];
  REP(i, n) { cin >> p[i]; --p[i]; }

  memset(dp, -1, sizeof dp);
  if (solve(0, 1) || solve(1, 1))
    puts("YES");
  else
    puts("NO");

  return 0;
}