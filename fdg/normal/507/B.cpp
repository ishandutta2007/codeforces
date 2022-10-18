#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>
#include <cmath>

using namespace std;

int main() {
  long long r, x, y, x1, y1;
  cin >> r >> x >> y >> x1 >> y1;
  double d = sqrt(0. + (x - x1) * (x - x1) + (y - y1) * (y - y1));
  cout << ceil(d / 2 / r) << endl; 
  return 0;
}