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
  vector<int> nabove(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &nabove[i]);
  vector<int> need_before(n);
  need_before[n - 1] = nabove[n - 1];
  for (int i = n - 2; i >= 0; --i)
    need_before[i] = max(nabove[i], need_before[i + 1] - 1);
  lint result = 0;
  int nhave = 0;
  for (int i = 0; i < n; ++i) {
    int res = 0;
    assert(nhave >= need_before[i]);
    if (nhave == 0) {
      ++nhave;
      assert(nabove[i] == 0);
    } else {
      res += nhave - nabove[i] - 1;
      if ((i + 1 < n && nhave < need_before[i + 1]) || nabove[i] == nhave) {
        ++nhave;
        ++res;
      }
    }
    result += res;
  }
  printf("%lld\n", result);
  return 0;
}