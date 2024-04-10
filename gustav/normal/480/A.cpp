#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)

const int inf = 1000000000;

#define MAXN 5005

int n, a, b;
int t[MAXN][2];
int dp[MAXN][2];

vector< pair< int, int > > p;

int main(void) {
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d%d", &a, &b);
    p.push_back({a, b});
  }

  sort(p.begin(), p.end());

  REP(i, n) t[i][0] = p[i].first, t[i][1] = p[i].second;

  for (int i = n - 1; i > 0; --i) {
    REP(j, 2) {
      dp[i][j] = inf;
      REP(k, 2) {
	if (i == n - 1) {
	  if (t[i - 1][j] <= t[i][k])
	    dp[i][j] = min(dp[i][j], t[i][k]);
	} else {
	  if (t[i - 1][j] <= t[i][k])
	    dp[i][j] = min(dp[i][j], dp[i + 1][k]);
	}
      }
    }
  }

  if (n == 1) {
    printf("%d\n", min(t[0][0], t[0][1]));
    exit(0);
  }

  printf("%d\n", min(dp[1][0], dp[1][1]));

  return 0;
}