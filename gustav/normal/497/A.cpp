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

const int MAX = 1005;

int n, m;
int diff[MAX];
char M[MAX][MAX];

int main(void)
{
  scanf("%d%d", &n, &m);

  REP(i, n) scanf("%s", M[i]);

  int sol = 0;

  REP(i, m) {
    bool remove = false;

    REP(j, n - 1) {
      if (diff[j]) continue;
      if (M[j][i] > M[j + 1][i]) remove = true;
    }

    if (remove) {
      ++sol;
    } else {
      REP(j, n - 1)
        if (M[j][i] != M[j + 1][i])
          diff[j] = true;
    }
  }

  printf("%d\n", sol);

  return 0;
}