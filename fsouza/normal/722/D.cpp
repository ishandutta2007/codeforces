#include <algorithm>
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
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

unordered_map<int, bool> used;

bool solve(const vector<int> &values, int limit, vector<int> &seq) {
  seq.clear();
  used.clear();
  bool result = true;

  for (int value : values) {
    while (value > limit)
      value /= 2;
    while (value > 0 && used[value] == true)
      value /= 2;
    if (value == 0) {
      result = false;
      break;
    }
    used[value] = true;
    seq.push_back(value);
  }

  return result;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> values(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &values[i]);

  vector<int> result;
  int l = 1, r = *max_element(values.begin(), values.end());
  while (l < r) {
    int m = l+(r-l)/2;
    if (solve(values, m, result)) r = m;
    else l = m+1;
  }
  solve(values, l, result);

  sort(result.begin(), result.end());
  for (int i = 0; i < (int)result.size(); ++i) {
    if (i > 0) printf(" ");
    printf("%d", result[i]);
  }
  printf("\n");

  return 0;
}