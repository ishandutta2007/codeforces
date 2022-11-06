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

vector<int> prices, discount;
vector<vector<int>> children;

struct result_t {
  int n;
  vector<lint> with_cupom;
  vector<lint> without_cupom;
  result_t() {}
  result_t(int _n)
    : n(_n), with_cupom(n + 1, LLONG_MAX), without_cupom(n + 1, LLONG_MAX) {
    with_cupom[0] = 0;
    without_cupom[0] = 0;
  }
};

result_t combine(const result_t &parent, const result_t &child) {
  const int np = parent.n, nc = child.n;
  result_t result(np + nc);
  for (int a = 0; a <= np; ++a)
    for (int b = 0; b <= nc; ++b) {
      result.with_cupom[a + b] =
        min(result.with_cupom[a + b],
            parent.with_cupom[a] + child.with_cupom[b]);
      result.without_cupom[a + b] =
        min(result.without_cupom[a + b],
            parent.without_cupom[a] + child.without_cupom[b]);
    }
  return result;
}

result_t dfs(int v) {
  result_t result;
  result.n = 1;
  result.with_cupom = {0LL, LLONG_MAX / 2};
  result.without_cupom = {0LL, (lint)prices[v]};
  for (int u : children[v])
    result = combine(result, dfs(u));

  for (lint &value : result.with_cupom)
    value += prices[v] - discount[v];
  result.with_cupom.insert(result.with_cupom.begin(), 0LL);
  result.with_cupom.pop_back();

  for (int i = 0; i <= result.n; ++i)
    result.with_cupom[i] = min(result.with_cupom[i], result.without_cupom[i]);

  return result;
}

int main() {
  int n, max_budget;
  scanf("%d %d", &n, &max_budget);

  prices.resize(n);
  discount.resize(n);
  children.resize(n);

  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &prices[i], &discount[i]);
    if (i > 0) {
      int p;
      scanf("%d", &p), --p;
      children[p].push_back(i);
    }
  }

  result_t result = dfs(0);

  int max_buy = 0;
  for (int i = 0; i <= n; ++i)
    if (result.with_cupom[i] <= max_budget)
      max_buy = i;
  printf("%d\n", max_buy);

  return 0;
}