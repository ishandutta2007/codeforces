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
  vector<pair<int, int>> edges;
  vector<int> last(k, 0), depth(k, 0);
  for (int i = 1; i < n; ++i) {
    int pos = i % k;
    edges.emplace_back(i, last[pos]);
    last[pos] = i;
    ++depth[pos];
  }
  nth_element(depth.begin(), depth.end() - 2, depth.end());
  printf("%d\n", depth[k - 2] + depth[k - 1]);
  for (int i = 0; i < n - 1; ++i)
    printf("%d %d\n", edges[i].first + 1, edges[i].second + 1);
  return 0;
}