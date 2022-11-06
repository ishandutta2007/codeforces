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

int main() {
  int n;
  scanf("%d", &n);
  vector<int> values(n);
  for (int &v : values) scanf("%d", &v);
  sort(values.begin(), values.end());

  const int maxv = 5000;
  vector<double> prob1(maxv+1, 0.0);
  for (int i = 0; i < n; ++i)
    for (int j = i+1; j < n; ++j)
      prob1[values[j] - values[i]] += 1.0;
  for (int v = 0; v <= maxv; ++v)
    prob1[v] /= n*(n-1)/2;

  vector<double> prob2(2*maxv+1, 0.0);
  for (int v = 0; v <= maxv; ++v)
    for (int u = 0; u <= maxv; ++u)
      prob2[v+u] += prob1[v] * prob1[u];

  double result = 0.0;
  for (int v = 0; v <= 2*maxv; ++v)
    for (int u = v+1; u <= maxv; ++u)
      result += prob2[v] * prob1[u];

  printf("%.10f\n", result);

  return 0;
}