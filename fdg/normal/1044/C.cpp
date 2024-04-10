#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<pair<int, int>> all;

int get(int a, int b, int c) {
  return abs(a - b) + abs(b - c) + abs(c - a);
}

int main() {
  int n;
  scanf("%d", &n);
  int minX = 1e+9, maxX = -1e+9, minY = 1e+9, maxY = -1e+9;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    all.push_back({x, y});

    minX = min(minX, x);
    maxX = max(maxX, x);
    minY = min(minY, y);
    maxY = max(maxY, y);
  }

  vector<pair<int, int>> cand;
  for (int i = 0; i < n; ++i) {
    if (all[i].first == minX || all[i].first == maxX || all[i].second == minY || all[i].second == maxY)
      cand.push_back(all[i]);
  }

  int ans3 = 0;
  for (int i = 0; i < cand.size(); ++i) {
    for (int j = i + 1; j < cand.size(); ++j) {
      for (int t = 0; t < all.size(); ++t) {
        if (all[t] == cand[i] || all[t] == cand[j]) continue;
        int cur = get(cand[i].first, cand[j].first, all[t].first)
                + get(cand[i].second, cand[j].second, all[t].second);
        ans3 = max(ans3, cur);
      }
    }
  }

  printf("%d ", ans3);
  for (int i = 4; i <= n; ++i)
    printf("%d ", 2 * (maxX - minX + maxY - minY));
  printf("\n");
  return 0;
}