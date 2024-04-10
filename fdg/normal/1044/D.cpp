#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

struct ByAllBits {
  map<int, pair<int, int>> color;

  set<pair<int, int>> diff;

  bool debug = false;

  pair<int, int> get(int x) {
    if (color.count(x)) {
      if (color[x].first == x)
        return color[x];
      else {
        pair<int, int> toPar = color[x];
        pair<int, int> fromParent = get(toPar.first);
        return color[x] = {fromParent.first, fromParent.second ^ toPar.second};
      }
    } else {
      return color[x] = {x, 0};
    }
  }

  void join(int x, int y, int edgeXor) {
    pair<int, int> valX = get(x);
    pair<int, int> valY = get(y);

    color[valX.first] = {valY.first, valX.second ^ edgeXor ^ valY.second};
  }

  int getXor(int x, int y) {
    pair<int, int> valX = get(x);
    pair<int, int> valY = get(y);

    if (valX.first == valY.first)
      return valX.second ^ valY.second;

    return -1;
  }
} solver;

int main() {
  int last = 0;

  int q;
  scanf("%d", &q);
  while (q--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int l, r, x;
      scanf("%d%d%d", &l, &r, &x);
      l ^= last;
      r ^= last;
      x ^= last;
      if (l > r) swap(l, r);
      // cout << "Q1:  " << l << " " << r << " " << x << " Last: " << last << endl;

      int value = solver.getXor(l - 1, r);
      if (value == -1) {
        solver.join(l - 1, r, x);
      }
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      l ^= last;
      r ^= last;
      if (l > r) swap(l, r);
      // cout << "Q2: " << l << "  " << r << endl;
      
      last = solver.getXor(l - 1, r);
      printf("%d\n", last);
      if (last == -1) last = 1;
    }
  }
  return 0;
}