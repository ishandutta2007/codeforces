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
  int n;
  scanf("%d", &n);
  string a = read_string();
  string b = read_string();
  int count[2][2] = {};
  for (int i = 0; i < n; ++i)
    count[a[i] - '0'][b[i] - '0'] += 1;

  lint result = 0;
  for (int prev_a = 0; prev_a < 2; ++prev_a)
    for (int prev_b = 0; prev_b < 2; ++prev_b)
      for (int next_a = 0; next_a < 2; ++next_a)
        for (int next_b = 0; next_b < 2; ++next_b) {
          int prev_state = (prev_a | prev_b) * 2 + (next_a | next_b);
          int next_state = (next_a | prev_b) * 2 + (prev_a | next_b);
          if (prev_state != next_state) {
            result += (lint)count[prev_a][prev_b] * count[next_a][next_b];
          }
        }
  result /= 2LL;
  printf("%lld\n", result);

  return 0;
}