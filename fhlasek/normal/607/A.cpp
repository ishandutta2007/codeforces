/* Written by Filip Hlasek 2015 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 111111
vector< pair<int, int> > beacon, by_left;
int dp[MAXN];

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  REP(i, N) {
    int a, b;
    scanf("%d%d", &a, &b);
    beacon.push_back(make_pair(a, b));
  }
  sort(beacon.begin(), beacon.end());
  REP(i, N) {
    int a = beacon[i].first, b = beacon[i].second;
    by_left.push_back(make_pair(a - b, i));
  }
  sort(by_left.begin(), by_left.end());
  int pos = 0;
  REP(i, N) {
    while (beacon[pos].first < by_left[i].first) pos++;
    dp[by_left[i].second + 1] = dp[pos] + (by_left[i].second - pos);
  }

  // REP(i, N + 1) printf("i: %d dp: %d\n", i, dp[i]);

  int ans = N;
  REP(i, N) ans = min(ans, i + dp[N - i]);
  printf("%d\n", ans);
  return 0;
}