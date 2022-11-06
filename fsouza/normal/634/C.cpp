#include <algorithm>
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
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

struct Bit {
  int n;
  vector<int> vals;
  Bit(int n): n(n), vals(n+1) {}
  void update(int i, int delta) {
    for (++i; i <= n; i += i&-i)
      vals[i] += delta;
  }
  int query(int i) {
    int res = 0;
    for (++i; i > 0; i -= i&-i)
      res += vals[i];
    return res;
  }
};

struct HalfSolver {
  int n, maxrate;
  vector<int> vals;
  Bit bit;
  HalfSolver(int n, int maxrate): n(n), maxrate(maxrate), vals(n, 0), bit(n) {}
  void update(int i, int delta) {
    int newv = min(maxrate, vals[i] + delta);
    delta = newv - vals[i];
    vals[i] = newv;
    bit.update(i, delta);
  }
  int query(int from, int to) {
    return bit.query(to) - (from-1 >= 0 ? bit.query(from-1) : 0);
  }
};

int main() {
  int n, k, good, bad, nq;
  scanf("%d %d %d %d %d", &n, &k, &good, &bad, &nq);
  HalfSolver hsg(n, good), hsb(n, bad);

  for (int q = 0; q < nq; ++q) {
    int kind;
    scanf("%d", &kind);
    if (kind == 1) {
      int day, many;
      scanf("%d %d", &day, &many), --day;
      hsg.update(day, many);
      hsb.update(day, many);
    } else {
      int day;
      scanf("%d", &day), --day;
      int result = hsb.query(0, day-1) + hsg.query(day+k, n-1);
      printf("%d\n", result);
    }
  }

  return 0;
}