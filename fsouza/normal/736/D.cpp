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
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

const int maxn = 2000;

struct matrix {
  int n;
  vector<bitset<maxn>> lines;
  matrix(int _n): n(_n), lines(n) {}
  static matrix identity(int n) {
    matrix result(n);
    for (int i = 0; i < n; ++i)
      result.set(i, i);
    return result;
  }
  void set(int y, int x) {
    lines[y].set(x);
  }
  bool get(int y, int x) {
    return lines[y].test(x);
  }
  void invert() {
    matrix result = matrix::identity(n);
    for (int y = 0; y < n; ++y) {
      int y2;
      for (y2 = y; y2 < n; ++y2)
        if (get(y2, y))
          break;
      assert(y2 < n);
      swap_lines(y2, y);
      result.swap_lines(y2, y);
      for (y2 = 0; y2 < n; ++y2) {
        if (y2 != y && get(y2, y)) {
          xor_lines(y, y2);
          result.xor_lines(y, y2);
        }
      }
    }
    *this = result;
  }
  void swap_lines(int a, int b) {
    swap(lines[a], lines[b]);
  }
  void xor_lines(int from, int to) {
    lines[to] ^= lines[from];
  }
};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  matrix mat(n);
  vector<pair<int, int>> positions(m);
  for (int i = 0; i < m; ++i) {
    int y, x;
    scanf("%d %d", &y, &x), --y, --x;
    positions[i] = make_pair(y, x);
    mat.set(y, x);
  }
  mat.invert();
  for (int i = 0; i < m; ++i) {
    int y, x;
    tie(y, x) = positions[i];
    if (mat.get(x, y)) printf("NO\n");
    else printf("YES\n");
  }

  return 0;
}