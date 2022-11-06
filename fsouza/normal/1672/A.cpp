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
  const int maxv = 50;
  vector<int> grundy(maxv + 1, 0);
  for (int v = 2; v <= maxv; ++v) {
    vector<int> next;
    for (int u = 1; u <= v - 1; ++u) {
      next.push_back(grundy[u] ^ grundy[v - u]);
    }
    sort(next.begin(), next.end());

    int pos = 0;
    for (int k = 0;; ++k) {
      while (pos != (int)next.size() && next[pos] < k) ++pos;
      if (pos == (int)next.size() || next[pos] > k) {
        grundy[v] = k;
        break;
      }
    }
  }

  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int n;
    scanf("%d", &n);
    int res = 0;
    for (int i = 0; i < n; ++i) {
      int size;
      scanf("%d", &size);
      res ^= grundy[size];
    }
    if (res != 0) printf("errorgorn\n");
    else printf("maomao90\n");
  }

  return 0;
}