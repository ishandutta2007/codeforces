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

int read_and_sum() {
  int res = 0;
  for (int i = 0; i < 4; ++i) {
    int v;
    scanf("%d", &v);
    res += v;
  }
  return res;
}

int main() {
  int n;
  scanf("%d", &n);
  int s1 = read_and_sum();
  int result = 0;
  for (int i = 0; i < n - 1; ++i) {
    int s2 = read_and_sum();
    if (s2 > s1) {
      ++result;
    }
  }
  printf("%d\n", result + 1);
  return 0;
}