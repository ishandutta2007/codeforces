#include <algorithm>
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
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

inline bool sorted(const vector<int> &v) {
  for (int i = 0; i+1 < (int)v.size(); ++i)
    if (v[i] > v[i+1])
      return false;
  return true;
}

bool possible(vector<int> &line, int c, int d) {
  const int n = line.size();
  bool result = false;

  for (int a = 0; a < n; ++a)
    for (int b = a; b < n; ++b) {
      swap(line[a], line[b]);
      swap(line[c], line[d]);
      if (sorted(line)) result = true;
      swap(line[c], line[d]);
      swap(line[a], line[b]);
    }

  for (int a = 0; a < n; ++a)
    for (int b = a; b < n; ++b) {
      swap(line[c], line[d]);
      swap(line[a], line[b]);
      if (sorted(line)) result = true;
      swap(line[a], line[b]);
      swap(line[c], line[d]);
    }

  return result;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  vector<vector<int>> table(n, vector<int>(m, 0));

  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      scanf("%d", &table[y][x]);
    }
  }

  bool result = false;

  for (int x0 = 0; x0 < m; ++x0)
    for (int x1 = x0; x1 < m; ++x1) {
      bool ok = true;
      for (int y = 0; y < n; ++y) {
        if (!possible(table[y], x0, x1)) {
          ok = false;
          break;
        }
      }
      if (ok) result = true;
    }

  if (result) printf("YES\n");
  else printf("NO\n");

  return 0;
}