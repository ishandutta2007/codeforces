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
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<bool> can_be_center(n, true);
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c), --a, --b, --c;
      can_be_center[b] = false;
    }
    int center = -1;
    for (int i = 0; i < n; ++i) {
      if (can_be_center[i]) {
        center = i;
        break;
      }
    }
    assert(center != -1);
    for (int i = 0; i < n; ++i)
      if (i != center)
        printf("%d %d\n", i + 1, center + 1);
  }
  return 0;
}