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

int main() {
  int n;
  scanf("%d", &n);

  int result = 0;
  map<pair<int, int>, int> many;
  int x = 0, y = 0;
  ++many[{x, y}];
  for (int i = 0; i < n; ++i) {
    char c;
    scanf(" %c", &c);
    switch (c) {
    case 'U':
      ++y;
      break;
    case 'D':
      --y;
      break;
    case 'L':
      --x;
      break;
    case 'R':
      ++x;
      break;
    default:
      assert(0);
    }
    result += many[{x, y}];
    ++many[{x, y}];
  }

  printf("%d\n", result);

  return 0;
}