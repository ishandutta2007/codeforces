#include <algorithm>
#include <array>
#include <bitset>
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
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n;
  scanf("%d", &n);
  int nc = n;
  vector<set<int>> with_color(nc);
  for (int i = 0; i < n; ++i) {
    int c;
    scanf("%d", &c), --c;
    with_color[c].insert(i);
  }
  int result = 0;
  for (set<int> ids : with_color) {
    if (ids.empty()) continue;
    int last = *ids.rbegin();
    int first = -1;
    for (int i = 0; i < last; ++i)
      if (ids.find(i) == ids.end()) {
        first = i;
        break;
      }
    if (first != -1) {
      result = max(result, last - first);
    }
  }
  printf("%d\n", result);
  return 0;
}