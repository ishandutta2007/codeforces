/* Written by Filip Hlasek 2018 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

#define FOR(i, a, b)   for (int i = (a); i <= (b); i++)
#define FORD(i, a, b)  for (int i = (a); i >= (b); i--)
#define REP(i, b)      for (int i =  0 ; i <  (b); i++)

using namespace std;

#define MAXN 222222
char c[MAXN];

int main(int argc, char *argv[]) {
  scanf("%s", c);
  int N = strlen(c);
  REP(i, N) c[i + N] = c[i];
  int ans = 1;
  int len = 1;
  REP(i, 2 * N - 1) {
    if ((c[i + 1] == 'b') == (c[i] == 'b')) len = 1;
    else { len++; ans = max(ans, len); }
  }
  printf("%d\n", min(ans, N));
  return 0;
}