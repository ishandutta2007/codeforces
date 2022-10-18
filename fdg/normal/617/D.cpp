#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

bool check(int x1, int y1, int x2, int y2, int x3, int y3) {
  return min(x1, x2) <= x3 && x3 <= max(x1, x2)
      && min(y1, y2) <= y3 && y3 <= max(y1, y2)
      && (x3 == x1 || x3 == x2 || y3 == y1 || y3 == y2);
}

int main() {
  int x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  if (x1 == x2 && x2 == x3 || y1 == y2 && y2 == y3) {
    cout << 1 << endl;
    return 0;
  }
  if (check(x1, y1, x2, y2, x3, y3) || check(x3, y3, x1, y1, x2, y2) || check(x3, y3, x2, y2, x1, y1)) {
    cout << 2 << endl;
    return 0;
  }
  cout << 3 << endl;
  return 0;
}