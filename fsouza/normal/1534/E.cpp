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
  int n, k;
  scanf("%d %d", &n, &k);
  if (n % 2 == 1 && k % 2 == 0) {
    printf("-1\n");
    return 0;
  }
  vector<int> count(n, 1);
  int max_count = 1;
  int cur2 = 0;

  int x3 = 0;
  while ((n + 2 * x3) % k != 0 || max_count > (n + 2 * x3) / k) {
    count[cur2] += 2;
    max_count = max(max_count, count[cur2]);

    cur2 += 1;
    if (cur2 == n) cur2 = 0;

    ++x3;
  }
  int many = (n + 2 * x3) / k;

  vector<vector<int>> ops(many);
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    int nrep = count[i];
    for (int rep = 0; rep < nrep; ++rep) {
      while ((int)ops[cur].size() == k) {
        ++cur;
        if (cur == many) cur = 0;
      }
      ops[cur].push_back(i);
      ++cur;
      if (cur == many) cur = 0;
    }
  }

  int result = 0;
  for (const vector<int> &op : ops) {
    printf("?");
    for (int pos : op)
      printf(" %d", pos + 1);
    printf("\n");
    fflush(stdout);
    int v;
    scanf("%d", &v);
    result ^= v;
  }
  printf("! %d\n", result);
  return 0;
}