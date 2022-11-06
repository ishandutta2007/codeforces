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
typedef unsigned long long ulint;

int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b%a, a);
}

lint solve(int m, int a, int b) {
  int size = (a + b) * 5 + 10;

  vector<int> min_right(size, -1);
  priority_queue<pair<int, int>> pq;
  min_right[0] = 0;
  pq.push({-min_right[0], 0});
  while (!pq.empty()) {
    pair<int, int> negmr_pos = pq.top();
    pq.pop();
    int negmr, pos;
    tie(negmr, pos) = negmr_pos;
    if (negmr != -min_right[pos])
      continue;

    if (pos + a < size &&
        (min_right[pos + a] == -1 || min_right[pos + a] > max(pos + a, min_right[pos]))) {
      min_right[pos + a] = max(pos + a, min_right[pos]);
      pq.push({-min_right[pos + a], pos + a});
    }

    if (pos - b >= 0 &&
        (min_right[pos - b] == -1 || min_right[pos - b] > max(pos - b, min_right[pos]))) {
      min_right[pos - b] = max(pos - b, min_right[pos]);
      pq.push({-min_right[pos - b], pos - b});
    }
  }

  ulint result = 0LL;
  for (int i = 0; i < size; ++i)
    if (min_right[i] != -1)
      result += max(m - min_right[i] + 1, 0);

  int g = gcd(a, b);

  int first = size - (size % g);
  if (first < size) first += g;
  int last = m - m % g;

  if (first <= last) {
    ulint many = (last - first) / g + 1LL;
    result += (ulint)(m + 1) * many;
    result -= many * (ulint)(first + last) / 2LL;
  }

  return (lint)result;
}

int main() {
  int m, a, b;
  scanf("%d %d %d", &m, &a, &b);
  printf("%lld\n", solve(m, a, b));
  return 0;
}