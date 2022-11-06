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

const int mod = 1e9 + 7;

vector<int> p2mod;

int solve(vector<int> a) {
  const int n = a.size();
  sort(a.begin(), a.end());
  lint result = 0;
  for (int i = 0; i < n; ++i) {
    result += (lint)a[i] * p2mod[i] % mod;
  }
  return (result % mod + mod) % mod;
}

int main() {
  int n;
  scanf("%d", &n);

  p2mod.push_back(1);
  for (int i = 1; i < n; ++i) {
    int next = 2 * p2mod.back();
    if (next >= mod) next -= mod;
    p2mod.push_back(next);
  }

  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);

  lint result = 0;
  result += solve(a);
  for (int &v : a) v = -v;
  result += solve(a);

  result = (result % mod + mod) % mod;

  printf("%d\n", (int)result);

  return 0;
}