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
    lint maxv;
    scanf("%d %lld", &n, &maxv);
    lint minv = (maxv + 1) / 2;
    vector<pair<lint, int>> values;
    for (int i = 0; i < n; ++i) {
      lint v;
      scanf("%lld", &v);
      values.push_back({v, i});
    }
    sort(values.begin(), values.end());
    lint cur = 0;
    vector<int> result;
    for (int i = n - 1; i >= 0; --i) {
      if (cur + values[i].first <= maxv) {
        cur += values[i].first;
        result.push_back(values[i].second);
      }
    }
    if (cur >= minv) {
      sort(result.begin(), result.end());
      printf("%d\n", (int)result.size());
      for (int i = 0; i < (int)result.size(); ++i) {
        if (i > 0) printf(" ");
        printf("%d", result[i] + 1);
      }
      printf("\n");
    } else {
      printf("-1\n");
    }
  }
  return 0;
}