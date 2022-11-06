#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>

typedef long long lint;

using namespace std;

int main() {
  int ret = 0;

  for (int y = 0; y < 5; y++)
    for (int x = 0; x < 5; x++) {
      int v;
      cin >> v;
      if (v)
        ret += abs(y - 2) + abs(x - 2);
    }

  cout << ret << endl;

  return 0;
}