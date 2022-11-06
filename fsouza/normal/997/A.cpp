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

string read_string() {
  char *str;
  scanf("%ms", &str);
  string result(str);
  free(str);
  return result;
}

int main() {
  int n, cost1, cost2;
  scanf("%d %d %d", &n, &cost1, &cost2);
  string s = read_string();
  int nblock = 0;
  for (int i = 0; i < n; ++i)
    if (s[i] == '0' && (i + 1 == n || s[i + 1] == '1'))
      nblock += 1;
  lint result;
  if (nblock == 0) result = 0;
  else result = cost2 + (lint)(nblock - 1) * min(cost1, cost2);
  printf("%lld\n", result);
  return 0;
}