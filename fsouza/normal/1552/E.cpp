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

vector<pair<int, int>> solve(int nc, int k, const vector<int> &colors) {
  int n = nc * k;
  vector<vector<int>> pos(nc);
  for (int i = 0; i < n; ++i) {
    pos[colors[i]].push_back(i);
  }

  vector<pair<int, int>> result(nc);

  const int limit = (nc + (k - 2)) / (k - 1);
  vector<int> ncross(n, 0);
  auto get_max_ncross = [&](int a, int b) {
    int res = 0;
    for (int i = a; i <= b; ++i)
      res = max(res, ncross[i]);
    return res;
  };
  auto update_ncross = [&](int a, int b, int delta) {
    for (int i = a; i <= b; ++i)
      ncross[i] += delta;
  };

  vector<int> cur(nc, 1);
  vector<bool> done(nc, false);
  int ndone = 0;
  while (ndone < nc) {
    int cand = -1;
    int cand_to = -1;

    for (int c = 0; c < nc; ++c) {
      if (done[c]) continue;

      while (cur[c] < (int)pos[c].size() &&
             get_max_ncross(pos[c][cur[c] - 1], pos[c][cur[c]]) + 1 > limit) {
        ++cur[c];
      }
      if (cur[c] == (int)pos[c].size())
        continue;

      int to = pos[c][cur[c]];
      if (cand == -1 || to < cand_to) {
        cand = c;
        cand_to = to;
      }
    }

    assert(cand != -1);
    int c = cand;
    int from = pos[c][cur[c] - 1], to = pos[c][cur[c]];
    update_ncross(from, to, +1);
    done[c] = true;
    ++ndone;

    result[c] = {from, to};
  }

  return result;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> colors(n * k);
  for (int &c : colors)
    scanf("%d", &c), --c;
  for (pair<int, int> range : solve(n, k, colors))
    printf("%d %d\n", range.first + 1, range.second + 1);
  return 0;
}