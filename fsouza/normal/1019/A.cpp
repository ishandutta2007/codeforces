#include <algorithm>
#include <array>
#include <bitset>
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
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int nv, np;
  scanf("%d %d", &nv, &np);
  vector<vector<int>> ps(np);
  for (int i = 0; i < nv; ++i) {
    int id, cost;
    scanf("%d %d", &id, &cost), --id;
    ps[id].push_back(cost);
  }

  if (np == 1) {
    printf("0\n");
    return 0;
  }

  int nhave = ps[0].size();
  ps.erase(ps.begin());
  --np;

  for (vector<int> &costs : ps)
    sort(costs.begin(), costs.end());

  lint result = LLONG_MAX;
  multiset<int> can_buy;

  for (int will_have = max(1, nhave); will_have <= nv; ++will_have) {
    int want = will_have - nhave;
    lint res = 0;
    can_buy.clear();

    for (const vector<int> &costs : ps) {
      int need_buy = max(0, (int)costs.size() - (will_have - 1));
      for (int i = 0; i < need_buy; ++i) {
        res += costs[i];
        want -= 1;
      }
      for (int i = need_buy; i < (int)costs.size(); ++i)
        can_buy.insert(costs[i]);
    }

    while (want > 0) {
      assert(!can_buy.empty());
      res += *can_buy.begin();
      can_buy.erase(can_buy.begin());
      --want;
    }

    result = min(result, res);
  }

  printf("%lld\n", result);

  return 0;
}