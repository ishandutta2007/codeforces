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
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int half_solve(vector<int> &vals, int k) {
  int l = -1e9-1, r = 1e9+1;
  while (l < r) {
    int m = l+(r-l)/2;
    lint remain = k;
    for (int i = 0; i < (int)vals.size(); ++i) {
      if (vals[i] > m) {
	remain -= vals[i] - m;
	if (remain < 0) break;
      }
    }
    if (remain >= 0) r = m;
    else l = m+1;
  }
  return l;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> vals(n);
  for (int &v : vals) scanf("%d", &v);

  int up = half_solve(vals, k);
  for (int &v : vals) v = -v;
  int down = -half_solve(vals, k);

  int result;

  if (up > down) result = up-down;
  else {
    lint sum = 0;
    for (int v : vals) sum += v;
    if (sum%n == 0) result = 0;
    else result = 1;
  }

  printf("%d\n", result);

  return 0;
}