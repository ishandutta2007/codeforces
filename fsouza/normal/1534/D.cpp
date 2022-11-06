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
  int n;
  scanf("%d", &n);
  vector<vector<int>> dists(n, vector<int>(n, -1));
  auto query = [&](int v) {
    printf("? %d\n", v + 1);
    fflush(stdout);
    for (int i = 0; i < n; ++i) {
      int d;
      scanf("%d", &d);
      dists[v][i] = dists[i][v] = d;
    }
  };
  query(0);
  vector<vector<int>> per_dist(n);
  per_dist[0].push_back(0);
  int countm2[2] = {0, 0};
  for (int i = 1; i < n; ++i) {
    int d = dists[0][i];
    per_dist[d].push_back(i);
    countm2[d % 2] += 1;
  }
  int start_dist;
  if (countm2[0] <= countm2[1]) start_dist = 2;
  else start_dist = 1;
  for (int d = start_dist; d < n; d += 2)
    for (int v : per_dist[d])
      query(v);
  printf("!\n");
  for (int d = 1; d < n; ++d)
    for (int v : per_dist[d]) {
      for (int cand : per_dist[d - 1])
        if (dists[v][cand] == 1) {
          printf("%d %d\n", v + 1, cand + 1);
          break;
        }
    }
  fflush(stdout);
  return 0;
}