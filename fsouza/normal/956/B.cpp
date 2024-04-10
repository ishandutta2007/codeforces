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
typedef long double ldouble;

int main() {
  int n, max_diff;
  scanf("%d %d", &n, &max_diff);
  vector<int> energies(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &energies[i]);

  ldouble result = -1.0;
  for (int i = 0; i + 2 < n; ++i) {
    int j = i + 1;
    int k = upper_bound(energies.begin(), energies.end(), energies[i] + max_diff) - energies.begin() - 1;
    if (k > j) {
      ldouble eff = ((ldouble)energies[k] - energies[j]) / (energies[k] - energies[i]);
      result = max(result, eff);
    }
  }

  if (result == -1.0) printf("-1\n");
  else printf("%.16f\n", (double)result);

  return 0;
}