#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n;
  scanf("%d", &n);

  const int ncand = 100000;
  vector<int> score(ncand, 0);

  int nhave = 0;
  vector<int> to(n), cost(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &to[i], &cost[i]), --to[i];
    if (to[i] == -1) ++nhave;
    else ++score[to[i]];
  }

  int pricefull = 0;
  int nfromfull = 0;
  set<pair<int, int>> full;

  vector<set<pair<int, int>>> voters(ncand);
  for (int i = 0; i < n; ++i)
    if (to[i] != -1) {
      voters[to[i]].insert({cost[i], i});
      full.insert({cost[i], i});
    }

  auto past = full.begin();

  vector<vector<int>> withscore(n+1);
  for (int j = 0; j < ncand; ++j)
    withscore[score[j]].push_back(j);

  int result = INT_MAX;

  int res = 0;
  for (int with = n; with >= 1; --with) {
    for (int j : withscore[with]) {
      pair<int, int> change = *voters[j].begin();

      --score[j];
      ++nhave;
      to[change.second] = -1;
      cost[change.second] = 0;

      if (past == full.end() || change < *past) {
	pricefull -= change.first;
	--nfromfull;
      }
      if (past != full.end() && *past == change)
	++past;
      full.erase(change);
      voters[j].erase(change);

      withscore[with-1].push_back(j);
      res += change.first;
    }
    withscore[with].clear();

    int need = max(0, with - nhave);
    while (nfromfull < need) {
      assert(past != full.end());
      pricefull += past->first;
      ++nfromfull;
      ++past;
    }
    while (nfromfull > need) {
      assert(past != full.begin());
      --past;
      --nfromfull;
      pricefull -= past->first;
    }

    result = min(result, res + pricefull);
  }

  printf("%d\n", result);

  return 0;
}