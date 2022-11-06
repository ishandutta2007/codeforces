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

lint query(int a, int b) {
  printf("? %d %d\n", a + 1, b + 1);
  fflush(stdout);
  lint res;
  scanf("%lld", &res);
  if (res == -1) exit(0);
  return res;
}

void output(int a, int b, int c) {
  printf("! %d %d %d\n", a + 1, b + 1, c + 1);
  fflush(stdout);
}

int find_block_size(lint ninv, int lim) {
  int l = 1, r = lim;
  while (l < r) {
    int m = (l + r) / 2;
    if ((lint)m * (m - 1) / 2LL < ninv) l = m + 1;
    else r = m;
  }
  return l;
}

int main() {
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int n;
    scanf("%d", &n);

    int l = 1, r = n;
    while (l < r) {
      int m = (l + r) / 2;
      if (query(0, m - 1) == 0) l = m + 1;
      else r = m;
    }
    int end_pair = l;
    int block1size = query(end_pair - 2, n - 1) -
      query(end_pair - 1, n - 1) + 1;
    int end_block1 = end_pair - 2 + block1size;
    int start_block1 = end_block1 - block1size;

    lint many_inv_block2 = query(end_block1, n - 1);

    int block2size = find_block_size(many_inv_block2, n);
    output(start_block1, end_block1, end_block1 + block2size - 1);
  }
  return 0;
}