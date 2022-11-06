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

int query(int i) {
  printf("? %d\n", i + 1);
  fflush(stdout);
  int res;
  scanf("%d", &res);
  return res;
}

void answer(int ans) {
  printf("! %d\n", (ans == -1 ? -1 : ans + 1));
  exit(0);
}

int main() {
  int n;
  scanf("%d", &n);

  if (n % 4 != 0) answer(-1);

  int half = n / 2;

  int l = 0;
  int vl = query(l) - query(l + half);
  if (vl == 0) answer(l);

  int r = half - 1;
  int vr = query(r) - query(r + half);
  if (vr == 0) answer(r);

  assert((lint)vl * vr < 0);
  assert((vr - vl) % 2 == 0);

  while (true) {
    int m = l + (r - l) / 2;
    int vm = query(m) - query(m + half);
    if (vm == 0) answer(m);
    if ((lint)vl * vm < 0) {
      r = m;
      vr = vm;
    } else {
      l = m;
      vl = vm;
    }
  }

  return 0;
}