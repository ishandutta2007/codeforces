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

int sg1(int x) {
  if (x < 5) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    if (x == 2) return 0;
    if (x == 3) return 1;
    if (x == 4) return 2;
  }
  if (x % 2) return 0;
  int tmp = sg1(x / 2);
  if (tmp == 1) return 2;
  return 1;
}

int sg0(int x) {
  if (x < 3) return x;
  return 1 - (x % 2);
}

int main(int argc, char *argv[]) {
  int N, K;
  scanf("%d%d", &N, &K);
  int x = 0, a;
  while (N--) {
    scanf("%d", &a);
    if (K % 2) x ^= sg1(a);
    else x ^= sg0(a);
  }
  if (x) printf("Kevin\n");
  else printf("Nicky\n");

  return 0;
}