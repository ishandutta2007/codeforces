#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int main() {
  int x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  cout << ((abs(x - z) * t2 + abs(x - y) * t2 + 3 * t3) <= (abs(x - y) * t1) ? "YES" : "NO") << endl;
  return 0;
}