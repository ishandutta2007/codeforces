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

int A[1111111];

int main(int argc, char *argv[]) {
  int N, Q;
  scanf("%d%d", &N, &Q);
  int pos1 = 0, pos2 = 1;
  while (Q--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int x;
      scanf("%d", &x);
      pos1 += x; if (pos1 < 0) pos1 += N; if (pos1 >= N) pos1 -= N;
      pos2 += x; if (pos2 < 0) pos2 += N; if (pos2 >= N) pos2 -= N;
    }
    else {
      if (pos1 & 1) { pos1--; pos2++; }
      else          { pos1++; pos2--; }
      if (pos1 < 0) pos1 += N; if (pos1 >= N) pos1 -= N;
      if (pos2 < 0) pos2 += N; if (pos2 >= N) pos2 -= N;
    }
  }
  REP(i, N / 2) {
    A[(pos1 + 2 * i) % N] = 1 + 2 * i;
    A[(pos2 + 2 * i) % N] = 2 + 2 * i;
  }
  REP(i, N) {
    if (i) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  return 0;
}