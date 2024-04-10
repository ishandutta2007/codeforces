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
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int n;
    scanf("%d", &n);
    vector<int> values(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &values[i]);
    vector<pair<int, int>> vo(n);
    for (int i = 0; i < n; ++i)
      vo[i] = {values[i], i};
    sort(vo.begin(), vo.end());

    int max_block = 0;
    for (int j = 0, i = j; i != n; i = j) {
      while (j < n && vo[j].first == vo[i].first) ++j;
      max_block = max(max_block, j - i);
    }

    vector<int> goes_to(n), comes_from(n);
    for (int i = 0; i < n; ++i) {
      goes_to[vo[i].second] = i;
      comes_from[i] = vo[i].second;
    }

    if (max_block < n)
      rotate(vo.begin(), vo.begin() + max_block, vo.end());

    vector<int> result(n);
    for (int i = 0; i < n; ++i)
      result[comes_from[i]] = values[vo[i].second];

    for (int i = 0; i < n; ++i) {
      if (i > 0) printf(" ");
      printf("%d", result[i]);
    }
    printf("\n");
  }
  return 0;
}