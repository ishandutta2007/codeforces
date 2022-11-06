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

int query(int y) {
  printf("%d\n", y);
  fflush(stdout);
  int ans;
  scanf("%d", &ans);
  if (ans == 0) exit(0);
  return ans;
}

int main() {
  int max_value, n;
  scanf("%d %d", &max_value, &n);

  vector<bool> lied(n);
  for (int i = 0; i < n; ++i)
    lied[i] = (query(1) == -1);

  int pos = 0;
  int l = 1, r = max_value;
  while (l < r) {
    int m = l + (r - l) / 2;
    int ans = query(m);
    if (lied[pos % n]) ans *= -1;
    ++pos;
    if (ans == 1) l = m + 1;
    else r = m - 1;
  }
  query(l);

  return 0;
}