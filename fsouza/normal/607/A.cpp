#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <numeric>
#include <set>
#include <vector>

#define INF 1000000000

using namespace std;

typedef long long lint;

int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int>> ab(n);
  for (int i = 0; i < n; ++i) scanf("%d %d", &ab[i].first, &ab[i].second);
  sort(ab.begin(), ab.end());

  vector<int> dp(n);
  int result = 0;
  
  for (int i = 0; i < n; ++i) {
    int ai = ab[i].first, bi = ab[i].second;

    int j = lower_bound(ab.begin(), ab.end(), make_pair(ai - bi, -INF)) - ab.begin();

    int res = 1;
    if (j-1 >= 0) res += dp[j-1];

    dp[i] = res;

    result = max(result, res);
  }

  printf("%d\n", n-result);
  
  return 0;
}