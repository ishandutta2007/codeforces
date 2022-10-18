#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <stack>
#include <queue>
#include <vector>

#include <bitset>

#include <string>

#include <algorithm>
#include <functional>

#include <iostream>
#include <sstream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define L(n) ((n) << 1)
#define R(n) (L(n) | 1)

const int MAX = 1000005;
const int off = 1 << 20;

int t[off << 1];

void build(int n) {
  if (n >= off) return;
  build(L(n));
  build(R(n));
  t[n] = max(t[L(n)], t[R(n)]);
}

int query(int l, int r) {
  if (l > r) return 0;

  l += off;
  r += off;

  int ret = max(t[l], t[r]);

  while (l / 2 != r / 2) {
    if (l % 2 == 0) ret = max(ret, t[l ^ 1]);
    if (r % 2 == 1) ret = max(ret, t[r ^ 1]);
    l /= 2; r /= 2;
  } 

  return ret;
}


int main(void)
{
  int n, a;
  scanf("%d", &n);

  REP(i, n) {
    scanf("%d", &a);
    t[a + off] = a;
  }

  build(1);

  int sol = 0;
  for (int i = 2; i < MAX; ++i) {
    if (!t[i + off]) continue;
    for (int j = i; j <= MAX; j += i) {
      sol = max(sol, query(j, min(MAX, j + i) - 1) % i);
    }
  }

  printf("%d\n", sol);

  return 0;
}