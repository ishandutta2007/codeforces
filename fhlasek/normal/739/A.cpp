/* Written by Filip Hlasek 2016 */
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
  int N, M;
  scanf("%d%d", &N, &M);
  int m = N;
  while (M--) {
    int a, b;
    scanf("%d%d", &a, &b);
    m = min(m, b - a + 1);
  }
  printf("%d\n", m);
  REP(i, N) {
    if (i) printf(" ");
    printf("%d", i % m);
  }
  printf("\n");
  return 0;
}