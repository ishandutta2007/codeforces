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

#define MAXN 1111
int N;
char s[MAXN];
int ans[MAXN];

int main(int argc, char *argv[]) {
  scanf("%s", s);
  N = strlen(s);
  bool last = 1;
  FORD(i, N - 1, 0) {
    if (s[i] - 'a' != last) {
      ans[i] = 1;
      last = !last;
    }
  }
  REP(i, N) {
    if (i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}