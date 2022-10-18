/* Written by Filip Hlasek 2017 */
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
int N, Q, M;
int A[MAXN];
int T[MAXN], L[MAXN], R[MAXN];

int main(int argc, char *argv[]) {
  scanf("%d%d%d", &N, &Q, &M);
  REP(i, N) scanf("%d", A + i);
  REP(i, Q) scanf("%d%d%d", T + i, L + i, R + i);
  while (M--) {
    int b;
    scanf("%d", &b);
    FORD(q, Q - 1, 0) if (L[q] <= b && b <= R[q]) {
      if (T[q] == 1) {
        if (b == L[q]) b = R[q];
        else b--;
      } else {
        b = R[q] - (b - L[q]);
      }
    }
    printf("%d", A[b - 1]);
    if (M) printf(" ");
  }
  printf("\n");
  return 0;
}