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

#define MAXN 333333
int N, X[MAXN], Y[MAXN], mX, MX, mY, MY;

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) scanf("%d%d", X + i, Y + i);
  mX = MX = X[0];
  mY = MY = Y[0];
  REP(i, N) {
    mX = min(mX, X[i]);
    mY = min(mY, Y[i]);
    MX = max(MX, X[i]);
    MY = max(MY, Y[i]);
  }
  int ans3 = 0;
  REP(i, N) {
    ans3 = max(ans3, MX - X[i] + MY - Y[i]);
    ans3 = max(ans3, MX - X[i] + Y[i] - mY);
    ans3 = max(ans3, X[i] - mX + MY - Y[i]);
    ans3 = max(ans3, X[i] - mX + Y[i] - mY);
  }
  printf("%d", 2 * ans3);
  FOR(i, 4, N) printf(" %d", 2 * (MX - mX + MY - mY));
  printf("\n");
  return 0;
}