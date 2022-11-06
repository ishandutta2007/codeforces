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
    int c, d;
    scanf("%d %d", &c, &d);

    int result = -1;
    if ((c + d) % 2 != 0) {
      result = -1;
    } else if (c == 0 && d == 0) {
      result = 0;
    } else if (c == d || c == -d) {
      result = 1;
    } else {
      result = 2;
    }
    printf("%d\n", result);
  }
  return 0;
}