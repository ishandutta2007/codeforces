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

int npress[3][3];

int main() {
  for (int y = 0; y < 3; y++)
    for (int x = 0; x < 3; x++)
      cin >> npress[y][x];
  for (int y = 0; y < 3; y++) {
    for (int x = 0; x < 3; x++) {
      int ret = 1;
      for (int dy = -1; dy <= 1; dy++)
        for (int dx = -1; dx <= 1; dx++)
          if (0 <= min(y+dy, x+dx) && max(y+dy, x+dx) < 3 && abs(dy) + abs(dx) <= 1)
            ret ^= (npress[y+dy][x+dx]%2);
      cout << ret;
    }
    cout << endl;
  }

  return 0;
}