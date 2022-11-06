#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
  int x, y, a, b;

  cin >> x >> y >> a >> b;

  int ret = 0;

  for (int c = a; c <= x; c++)
    for (int d = b; d < c && d <= y; d++)
      ret++;

  cout << ret << endl;

  for (int c = a; c <= x; c++)
    for (int d = b; d < c && d <= y; d++)
      cout << c << " " << d << endl;

  return 0;
}