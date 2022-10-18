#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <unordered_set>
#include <map>
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

int n;
char buf[4];
int cnt[1 << 24], shift;
const int all = (1 << 24) - 1;

void spread(int l, int r) {
  if (l + 1 == r) return;
  int m = (l + r) / 2;

  for (int i = m; i < r; ++i)
    cnt[l + i - m] += cnt[i];

  spread(l, m);
  spread(m, r);
}

int main(void)
{
  scanf("%d", &n);

  REP(i, n) {
    scanf("%s", buf);
    int mask = 0;
    REP(j, 3)
      mask |= (1 << (buf[j] - 'a'));
    ++cnt[mask ^ all];
  }

  spread(0, 1 << 24);

  int sol = 0;
  REP(i, 1 << 24) sol ^= ((n - cnt[i]) * (n - cnt[i]));

  printf("%d\n", sol);

  return 0;
}