#include <algorithm>
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
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;
typedef unsigned long long ulint;

ulint solve(vector<int> a, vector<int> b) {
  ulint sa = 0, sb = 0;
  for (int v : a) sa += v;
  for (int v : b) sb += v;

  ulint result = 2ULL*LLONG_MAX;

  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());

  for (int nfixed = 1; nfixed <= (int)a.size(); ++nfixed) {
    sa -= a[nfixed-1];
    result = min(result, sa + sb * nfixed);
  }

  return result;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> a(n), b(m);
  for (int &v : a) scanf("%d", &v);
  for (int &v : b) scanf("%d", &v);
  printf("%llu\n", min(solve(a, b), solve(b, a)));

  return 0;
}