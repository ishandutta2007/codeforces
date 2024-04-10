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
    int n;
    scanf("%d", &n);
    vector<int> values(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &values[i]);
    bool all_ok = true;
    for (int i = 0; i < n; ++i) {
      bool this_ok = false;
      for (int j = 0; j <= i; ++j)
        if (values[i] % (j + 2) != 0) {
          this_ok = true;
          break;
        }
      if (!this_ok) {
        all_ok = false;
        break;
      }
    }
    if (all_ok) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}