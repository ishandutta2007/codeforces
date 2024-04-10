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

int digits_sum(int num) {
  int result = 0;
  while (num > 0) {
    result += num % 10;
    num /= 10;
  }
  return result;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> result;
  for (int x = max(1, n - 81); x <= n; ++x)
    if (x + digits_sum(x) == n)
      result.push_back(x);
  printf("%d\n", (int)result.size());
  for (int x : result)
    printf("%d\n", x);
  return 0;
}