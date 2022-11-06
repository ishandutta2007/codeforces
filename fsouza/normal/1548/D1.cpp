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

int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b%a, a);
}

int main() {
  vector<vector<int>> many(2, vector<int>(2));

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    assert(x % 2 == 0);
    assert(y % 2 == 0);
    many[(x / 2) % 2][(y / 2) % 2] += 1;
  }

  lint result = 0LL;
  vector<pair<int, int>> cands;
  vector<lint> cand_count;
  for (int x0 = 0; x0 < 2; ++x0)
    for (int y0 = 0; y0 < 2; ++y0) {
      cands.emplace_back(x0, y0);
      cand_count.push_back(many[x0][y0]);
    }

  int nc = cands.size();

  for (int a = 0; a < nc; ++a)
    for (int b = a; b < nc; ++b)
      for (int c = b; c < nc; ++c) {

        int x0 = cands[a].first;
        int y0 = cands[a].second;
        int x1 = cands[b].first;
        int y1 = cands[b].second;
        int x2 = cands[c].first;
        int y2 = cands[c].second;

        int dx1 = x1 - x0;
        int dy1 = y1 - y0;
        int dx2 = x2 - x0;
        int dy2 = y2 - y0;

        lint many_way = 0LL;
        if (a < b && b < c) {
          many_way = (lint)cand_count[a] * cand_count[b] * cand_count[c];
        } else if (a < b && b == c) {
          many_way = (lint)cand_count[a] * cand_count[b] * (cand_count[b] - 1LL) / 2LL;
        } else if (a == b && b < c) {
          many_way = (lint)cand_count[a] * (cand_count[a] - 1LL) / 2LL * cand_count[c];
        } else if (a == b && b == c) {
          many_way = (lint)cand_count[a] * (cand_count[a] - 1LL) * (cand_count[a] - 2LL) / 6LL;
        } else {
          assert(false);
        }

        if ((gcd(abs(dx1), abs(dy1)) +
             gcd(abs(dx2-dx1), abs(dy2-dy1)) +
             gcd(abs(dx2), abs(dy2))) % 2 != 0) {
          continue;
        }

        result += many_way;
      }

  printf("%lld\n", result);

  return 0;
}