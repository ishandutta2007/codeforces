#include <cstdio>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 1000005;
const int inf = 1000000000;

int n;
vector< int > q;
int dp[MAXN];
int rc[MAXN];

int main(void) 
{
  FOR(i, 1, (1 << 6) + 1) {
    int num = 0;
    for (int j = 6; j >= 0; --j) {
      num *= 10;
      num += ((i >> j) & 1);
    }
    q.push_back(num);
  }

  sort(q.begin(), q.end());

  scanf("%d", &n);

  dp[0] = 0;
  FOR(i, 1, n + 1) {
    dp[i] = inf;
    for (int qq : q) {
      if (qq > i) break;
      if (dp[i] > 1 + dp[i - qq]) {
	dp[i] = 1 + dp[i - qq];
	rc[i] = qq;
      }
      dp[i] = min(dp[i], 1 + dp[i - qq]);
    }
  }

  printf("%d\n", dp[n]);
  vector< int > sol;

  while (n) {
    sol.push_back(rc[n]);
    n -= rc[n];
  }

  sort(sol.begin(), sol.end());
  REP(i, (int)sol.size())
    printf("%d%c", sol[i], " \n"[i + 1 == (int)sol.size()]);

  return 0;
}