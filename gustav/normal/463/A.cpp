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

int main(void)
{
  int n, s;
  scanf("%d%d", &n, &s);

  int best = -1;

  REP(i, n) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x * 100 + y > s * 100) continue;
    best = max(best, (100 - y) % 100);
  }

  printf("%d\n", best);

  return 0;
}