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
int Left[MAXN * 33], Right[MAXN * 33], Cnt[MAXN * 33];
int T = 1;

int A[MAXN];

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  REP(i, N) scanf("%d", A + i);
  REP(i, N) {
    int P;
    scanf("%d", &P);
    int v = 0;
    Cnt[v]++;
    FORD(b, 29, 0) {
      if (P & (1 << b)) {
        if (!Right[v]) Right[v] = T++;
        v = Right[v];
      } else {
        if (!Left[v]) Left[v] = T++;
        v = Left[v];
      }
      Cnt[v]++;
    }
  }
  REP(i, N) {
    int P = A[i];
    int v = 0;
    Cnt[v]--;
    FORD(b, 29, 0) {
      if (P & (1 << b)) {
        if (Right[v] && Cnt[Right[v]]) {
          v = Right[v];
          P ^= (1 << b);
        } else {
          v = Left[v];
        }
      } else {
        if (Left[v] && Cnt[Left[v]]) {
          v = Left[v];
        } else {
          v = Right[v];
          P ^= (1 << b);
        }
      }
      Cnt[v]--;
    }
    if (i) printf(" ");
    printf("%d", P);
  }
  printf("\n");
  return 0;
}