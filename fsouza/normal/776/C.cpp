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

const int maxv = 1e9;

int main() {
  int n, k;
  map<lint, int> acc_count;
  scanf("%d %d", &n, &k);
  vector<lint> possible_sums;
  if (k == 1) {
    possible_sums = {1};
  } else if (k == -1) {
    possible_sums = {-1, 1};
  } else {
    for (lint value = 1; abs(value) <= (lint)n * maxv; value *= k)
      possible_sums.push_back(value);
  }

  lint result = 0;
  lint acc = 0;
  ++acc_count[acc];
  for (int i = 0; i < n; ++i) {
    int v;
    scanf("%d", &v);
    acc += v;
    for (lint sum : possible_sums) {
      auto it = acc_count.find(acc - sum);
      if (it != acc_count.end())
        result += it->second;
    }
    ++acc_count[acc];
  }

  printf("%lld\n", result);

  return 0;
}