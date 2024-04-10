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

#define MAXN 100005
#define MAXM 100005

int n, m;
int l[MAXM];
int r[MAXM];
int q[MAXM];
int a[MAXN];
int b[MAXN];
int c[MAXN];

bool solve(int bit) {
  memset(b, 0, sizeof b);
  memset(c, 0, sizeof c);

  REP(i, m) {
    if (((q[i] >> bit) & 1) == 0) continue;
    ++b[l[i]];
    --b[r[i] + 1];
  }
  
  int cut = 0;
  REP(i, n) {
    cut += b[i];
    if (cut) {
      a[i] |= (1 << bit);
      c[i] = 1;
    }
  }

  FOR(i, 1, n) c[i] += c[i - 1];

  REP(i, m) {
    if (((q[i] >> bit) & 1) == 1) continue;
    int sum = c[r[i]];
    if (l[i]) sum -= c[l[i] - 1];
    if (sum == r[i] - l[i] + 1) return false;
  }

  return true;
}

int main(void)
{
  scanf("%d%d", &n, &m);
  REP(i, m) {
    scanf("%d%d%d", l + i, r + i, q + i);
    --l[i]; --r[i];
  }

  REP(i, 30) {
    if (!solve(i)) {
      puts("NO");
      exit(0);
    }
  }

  puts("YES");
  REP(i, n) printf("%d ", a[i]);
  puts("");

  return 0;
}