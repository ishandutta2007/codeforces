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

lint gcd(lint a, lint b) {
  if (a == 0) return b;
  return gcd(b%a, a);
}

vector<pair<int, int>> factorize(int value) {
  vector<pair<int, int>> result;
  for (int p = 2; p * p <= value; ++p)
    if (value % p == 0) {
      int exp = 0;
      while (value % p == 0) {
        value /= p;
        ++exp;
      }
      result.emplace_back(p, exp);
    }
  if (value != 1) {
    result.emplace_back(value, 1);
    value = 1;
  }
  return result;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int>> values(n);
  lint g = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &values[i].first, &values[i].second);
    g = gcd(g, (lint)values[i].first * values[i].second);
  }

  if (g == 1) printf("-1\n");
  else {
    int result = -1;
    vector<pair<int, int>> fas = factorize(values[0].first);
    vector<pair<int, int>> fbs = factorize(values[0].second);
    for (pair<int, int> it : fas)
      if (g % it.first == 0)
        result = it.first;
    for (pair<int, int> it : fbs)
      if (g % it.first == 0)
        result = it.first;
    printf("%d\n", result);
  }

  return 0;
}