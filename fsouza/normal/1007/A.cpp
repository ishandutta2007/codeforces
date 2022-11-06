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
  vector<int> values(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &values[i]);
  sort(values.begin(), values.end());
  int j = n - 1;
  int result = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (values[j] > values[i]) {
      ++result;
      --j;
    }
  }
  printf("%d\n", result);
  return 0;
}