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
    for (int i = 0; i < n; ++i) {
      scanf("%*d");
    }
    printf("%d\n", 6 * (n/2));
    for (int i = 0; i + 1 < n; i += 2) {
      for (int kind : {2, 1, 2, 1, 2, 1}) {
        printf("%d %d %d\n", kind, i + 1, (i + 1) + 1);
      }
    }
  }
  return 0;
}