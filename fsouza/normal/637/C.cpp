#include <algorithm>
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
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n;
  scanf("%d", &n);
  vector<string> strs(n, string(6, ' '));

  int result = 6;
  for (int i = 0; i < n; ++i) {
    scanf("%s", &strs[i][0]);
    for (int j = 0; j < i; ++j) {
      int ndiff = 0;
      for (int k = 0; k < 6; ++k) ndiff += strs[i][k] != strs[j][k];
      result = min(result, (ndiff+1)/2-1);
    }
  }

  printf("%d\n", result);

  return 0;
}