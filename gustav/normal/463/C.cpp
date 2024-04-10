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

#define MAX 2005

int a[MAX][MAX];

llint d1[2 * MAX];
llint d2[2 * MAX];

int main(void)
{
  int n;
  scanf("%d", &n);
  REP(i, n) REP(j, n) scanf("%d", &a[i][j]);
  
  REP(i, n) REP(j, n) {
    d1[i + j] += a[i][j];
    d2[i - j + n] += a[i][j];
  }

  vector< llint > sol(2, -1);
  vector< pair< int, int > > r(2, {0, 0});

  REP(i, n) REP(j, n) {
    int k = (i + j) % 2;
    llint csol = d1[i + j] + d2[i - j + n] - a[i][j];

    if (csol > sol[k]) {
      sol[k] = csol;
      r[k] = {i + 1, j + 1};
    }
  }

  cout << sol[0] + sol[1] << endl;
  printf("%d %d %d %d\n", r[0].first, r[0].second, r[1].first, r[1].second);

  return 0;
}