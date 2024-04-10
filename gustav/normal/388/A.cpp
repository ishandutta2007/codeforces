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

#define MAXN 105

int n;
int x[MAXN];

int main(void)
{
  scanf("%d", &n);
  REP(i, n) scanf("%d", x + i);
  sort(x, x + n);

  int sol = 0;
  REP(i, n) {
    if (x[i] == -1) continue;
    ++sol;
    int got = 1;
    FOR(j, i + 1, n) {
      if (x[j] >= got) {
        x[j] = -1;
        ++got;
      }
    }
  }

  printf("%d\n", sol);

  return 0;
}