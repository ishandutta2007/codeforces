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

    values.push_back(0);
    values.insert(values.begin(), 0);
    n = values.size();

    lint result = 0LL;
    for (int i = 1; i + 1 < n; ++i) {
      result += abs(values[i] - values[i - 1]);

      int big_adj = max(values[i - 1], values[i + 1]);
      int remove = max(values[i] - big_adj, 0);
      result -= remove;
    }
    result += values[n - 2];

    printf("%lld\n", result);
  }
  return 0;
}