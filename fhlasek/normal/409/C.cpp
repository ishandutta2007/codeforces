/* Written by Filip Hlasek 2014 */
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
  int a, b, c, d, e;
  scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
  printf("%d\n", min(a, min(b, min(c / 2, min(d / 7, e / 4)))));
  return 0;
}