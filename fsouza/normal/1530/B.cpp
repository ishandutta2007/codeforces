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
    vector<pair<int, int>> plates;
    auto maybe_add = [&](int y, int x) {
      if (plates.empty()) {
        plates.emplace_back(y, x);
      } else {
        if (abs(plates.back().first - y) <= 1 &&
            abs(plates.back().second - x) <= 1) {
        } else if (abs(plates.front().first - y) <= 1 &&
                   abs(plates.front().second - x) <= 1) {
        } else {
          plates.emplace_back(y, x);
        }
      }
    };
    int h, w;
    scanf("%d %d", &h, &w);
    for (int x = 0; x < w; ++x)
      maybe_add(0, x);
    for (int y = 0; y < h; ++y)
      maybe_add(y, w - 1);
    for (int x = w - 1; x >= 0; --x)
      maybe_add(h - 1, x);
    for (int y = h - 1; y >= 0; --y)
      maybe_add(y, 0);
    vector<string> result(h, string(w, '0'));
    for (pair<int, int> plate : plates)
      result[plate.first][plate.second] = '1';
    for (int y = 0; y < h; ++y) {
      printf("%s\n", result[y].c_str());
    }
  }
  return 0;
}