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

#define MAXN 111111

struct Str {

  char s[MAXN];
  int S;

  int trailA[MAXN], prefB[MAXN];

  void load() {
    scanf("%s", s);
    S = strlen(s);
    prefB[0] = trailA[0] = 0;
    REP(i, S) {
      prefB[i + 1] = prefB[i];
      trailA[i + 1] = trailA[i] + 1;
      if (s[i] != 'A') {
        prefB[i + 1]++;
        trailA[i + 1] = 0;
      }
    }
  }

  int getB(int l, int r) {
    return prefB[r] - prefB[l - 1];
  }

  int getA(int l, int r) {
    return min(r - l + 1, trailA[r]);
  }

};

bool solve(int bs, int as, int bt, int at) {
  // printf("(%d %d %d %d)\n", bs, as, bt, at);
  if (bs % 2 != bt % 2 || bs > bt || at > as) return false;
  if (!bs && bt) {
    return as > at;
  }
  if ((as - at) % 3) {
    return bs < bt;
  }
  return true;
}

int main(int argc, char *argv[]) {
  Str S, T;
  S.load();
  T.load();
  int Q;
  scanf("%d", &Q);
  while (Q--) {
    int ls, rs, lt, rt;
    scanf("%d%d%d%d", &ls, &rs, &lt, &rt);
    int bs = S.getB(ls, rs), bt = T.getB(lt, rt);
    int as = S.getA(ls, rs), at = T.getA(lt, rt);
    printf("%d", solve(bs, as, bt, at) ? 1 : 0);
  }
  printf("\n");
  return 0;
}