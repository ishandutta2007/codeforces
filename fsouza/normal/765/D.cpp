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
  vector<int> f(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &f[i]), --f[i];
  vector<int> fixed;
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    if (f[i] == i) {
      fixed.push_back(i);
    } else if (f[f[i]] != f[i]) {
      ok = false;
      break;
    }
  }
  if (!ok) {
    printf("-1\n");
  } else {
    int m = fixed.size();
    vector<int> h(m), g(n);
    for (int i = 0; i < m; ++i) {
      h[i] = fixed[i];
      g[h[i]] = i;
    }
    for (int i = 0; i < n; ++i)
      if (f[i] != i)
        g[i] = g[f[i]];
    printf("%d\n", m);
    for (int i = 0; i < n; ++i) {
      if (i > 0) printf(" ");
      printf("%d", g[i] + 1);
    }
    printf("\n");
    for (int i = 0; i < m; ++i) {
      if (i > 0) printf(" ");
      printf("%d", h[i] + 1);
    }
    printf("\n");
  }
  return 0;
}