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
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 111111

int T[MAXN], X[MAXN], L[MAXN], C[MAXN], M;
long long q[MAXN];
int s = 0, Q;
int seq[MAXN];

int main(int argc, char *argv[]) {
  scanf("%d", &M);
  REP(i, M) {
    scanf("%d", T + i);
    if (T[i] == 1) scanf("%d", X + i);
    else scanf("%d%d", L + i, C + i);
  }

  scanf("%d", &Q);
  REP(i, Q) cin >> q[i];

  long long pos = 0;
  REP(i, M) {
    if (T[i] == 1) {
      if (pos < MAXN) seq[pos] = X[i];
      pos++;
      if (s < Q && q[s] == pos) {
        if (s) printf(" ");
        printf("%d", X[i]);
        s++;
      }
    }
    else {
      for (int j = 0; j < L[i] * C[i] && pos + j < MAXN; j++) seq[pos + j] = seq[j % L[i]];
      while (s < Q && q[s] <= pos + L[i] * C[i]) {
        if (s) printf(" ");
        printf("%d", seq[(q[s] - pos - 1) % L[i]]);
        s++;
      }
      pos += L[i] * C[i];
    }
  }
  printf("\n");
  return 0;
}