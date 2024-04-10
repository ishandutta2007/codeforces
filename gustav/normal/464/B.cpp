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

int x, y, z;
vector< int > v[8];

llint sq(llint x) { return x * x; }

int cnts[4];

bool check() {
  cnts[1] = cnts[2] = cnts[3] = 0;
  llint min_len = 1000000000000000000LL;
  FOR(i, 1, 8) {
    llint len = 0;
    REP(j, 3) len += sq(v[0][j] - v[i][j]);
    min_len = min(min_len, len);
  }
  if (min_len == 0) return false;
  REP(i, 8) FOR(j, i + 1, 8) {
    llint len = 0;
    REP(k, 3) len += sq(v[i][k] - v[j][k]);
    if (len == 0) return false;
    if (len % min_len != 0 || len / min_len > 3) return false;
    ++cnts[len / min_len];
  }
  if (cnts[1] != 12) return false;
  if (cnts[2] != 12) return false;
  if (cnts[3] != 4) return false;
  return true;
}

void yes() {
  puts("YES");
  REP(i, 8) printf("%d %d %d\n", v[i][0], v[i][1], v[i][2]);
  exit(0);
}

void go(int n) {
  if (n == 8) {
    if (check()) yes();
    return;
  }

  sort(v[n].begin(), v[n].end());

  do {
    go(n + 1);
  } while (next_permutation(v[n].begin(), v[n].end()));
}

int main(void)
{
  REP(i, 8) {
    scanf("%d%d%d", &x, &y, &z);
    v[i].push_back(x);
    v[i].push_back(y);
    v[i].push_back(z);
  }

  go(0);

  puts("NO");

  return 0;
}