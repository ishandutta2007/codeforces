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

const int mod = 1e9 + 7;

int main() {
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int n;
    scanf("%d", &n);
    vector<int> pa(n), pb(n);
    for (vector<int> *p : {&pa, &pb})
      for (int i = 0; i < n; ++i)
        scanf("%d", &(*p)[i]), --(*p)[i];
    vector<int> next(n);
    for (int i = 0; i < n; ++i) {
      next[pa[i]] = pb[i];
    }
    int result = 1;
    for (int i = 0; i < n; ++i) {
      if (next[i] == -1) continue;
      int j = i;
      do {
        int to = next[j];
        next[j] = -1;
        j = to;
      } while (j != i);
      result += result;
      if (result >= mod) result -= mod;
    }
    printf("%d\n", result);
  }
  return 0;
}