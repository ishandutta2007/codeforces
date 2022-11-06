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

int get_or(int i, int j) {
  printf("or %d %d\n", i + 1, j + 1);
  fflush(stdout);
  int res;
  scanf("%d", &res);
  if (res == -1) exit(0);
  return res;
}

int get_and(int i, int j) {
  printf("and %d %d\n", i + 1, j + 1);
  fflush(stdout);
  int res;
  scanf("%d", &res);
  if (res == -1) exit(0);
  return res;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k), --k;

  vector<int> or_first(n), and_first(n);
  for (int i = 1; i < n; ++i) {
    or_first[i] = get_or(0, i);
    and_first[i] = get_and(0, i);
  }
  int or_next2 = get_or(1, 2);

  constexpr int nbit = 30;

  vector<int> first_bit_value(nbit, -1);
  for (int b = 0; b < nbit; ++b) {
    for (int i = 1; i < n; ++i) {
      if ((or_first[i] & (1<<b)) == 0) {
        first_bit_value[b] = 0;
      }
      if ((and_first[i] & (1<<b)) != 0) {
        first_bit_value[b] = 1;
      }
    }

    if (first_bit_value[b] == -1) {
      if ((or_next2 & (1<<b)) == 0) {
        first_bit_value[b] = 1;
      } else {
        first_bit_value[b] = 0;
      }
    }
  }

  vector<int> values(n);
  for (int b = 0; b < nbit; ++b)
    values[0] |= first_bit_value[b]<<b;
  for (int i = 1; i < n; ++i) {
    for (int b = 0; b < nbit; ++b) {
      if (first_bit_value[b] == 0) {
        if (or_first[i] & (1<<b))
          values[i] |= 1<<b;
      } else {
        if (and_first[i] & (1<<b))
          values[i] |= 1<<b;
      }
    }
  }

  nth_element(values.begin(), values.begin() + k, values.end());
  printf("finish %d\n", values[k]);
  fflush(stdout);

  return 0;
}