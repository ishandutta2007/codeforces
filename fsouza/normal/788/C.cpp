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
  int target, nkind;
  scanf("%d %d", &target, &nkind);
  vector<int> deltas;
  for (int i = 0; i < nkind; ++i) {
    int v;
    scanf("%d", &v);
    deltas.push_back(v - target);
  }
  sort(deltas.begin(), deltas.end());
  deltas.resize(unique(deltas.begin(), deltas.end()) - deltas.begin());
  int limit = max(deltas.back(), -deltas.front());
  vector<int> _mindist(2 * limit + 1, INT_MAX);
  auto mindist = [limit, &_mindist](int v) -> int& {
    return _mindist[v + limit];
  };
  queue<int> q;
  for (int d : deltas) {
    mindist(d) = 1;
    q.push(d);
  }
  while (!q.empty()) {
    int v = q.front(); q.pop();
    for (int d : deltas) {
      int u = v + d;
      if (-limit <= u && u <= limit && mindist(u) == INT_MAX) {
        mindist(u) = mindist(v) + 1;
        q.push(u);
      }
    }
  }
  int result = mindist(0);
  if (result == INT_MAX) result = -1;
  printf("%d\n", result);
  return 0;
}