/* Written by Filip Hlasek 2015 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

int main(int argc, char *argv[]) {
  int a1, a2, a3, a4, a5, a6;
  scanf("%d%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5, &a6);
  int t = 2 * a1 - 1, ans = 0;
  REP(i, a2 + a3) {
    if (i < a2) t++;
    else if (i > a2) t--;
    if (i < a6) t++;
    else if (i > a6) t--;
    // printf("i: %d t: %d\n", i, t);
    ans += t;
  }
  printf("%d\n", ans);
  return 0;
}