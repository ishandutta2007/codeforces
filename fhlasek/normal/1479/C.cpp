/* Written by Filip Hlasek 2021 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, b) for (int i = 0; i < (b); i++)

using namespace std;

int N = 22;
int eA[444], eB[444], eC[444], M = 0;

void addEdge(int a, int b, int c) {
  eA[M] = a;
  eB[M] = b;
  eC[M] = c;
  M++;
}

int main(int argc, char* argv[]) {
  REP(i, 20) {
    int v = N - i - 1;
    addEdge(v, N, 1);
    REP(j, i) addEdge(v, N - j - 1, 1 << j);
  }

  int L, R;
  scanf("%d%d", &L, &R);
  addEdge(1, N, L);
  int total = L;
  REP(i, 20) if ((R - L) & (1 << i)) {
    addEdge(1, N - i - 1, total);
    total += (1 << i);
  }

  printf("YES\n%d %d\n", N, M);
  REP(i, M) printf("%d %d %d\n", eA[i], eB[i], eC[i]);

  return 0;
}