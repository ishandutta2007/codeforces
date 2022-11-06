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
  scanf("%d", &n), ++n;
  vector<bool> is_prime(n+1, true);
  is_prime[0] = is_prime[1] = false;
  for (int p = 2; p <= n; ++p)
    if (is_prime[p])
      for (int m = 2 * p; m <= n; m += p)
        is_prime[m] = false;
  int ncolor;
  if (n >= 4) ncolor = 2;
  else ncolor = 1;
  printf("%d\n", ncolor);
  for (int v = 2; v <= n; ++v) {
    if (v-1 >= 2) printf(" ");
    printf("%d", is_prime[v] ? 1 : 2);
  }
  printf("\n");
  return 0;
}