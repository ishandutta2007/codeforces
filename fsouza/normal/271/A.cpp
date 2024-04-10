#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <set>

typedef long long lint;

using namespace std;

bool distinct(int y) {
  int nd = 0;
  set<int> ds;
  while (y) {
    nd++;
    ds.insert(y%10);
    y /= 10;
  }
  return nd == (int)ds.size();
}

int main() {
  int y;
  cin >> y;
  int y2;
  for (y2 = y+1; !distinct(y2); y2++);
  cout << y2 << endl;
  return 0;
}