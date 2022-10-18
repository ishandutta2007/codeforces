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

#define MAXN 555555
int N, B[MAXN];
long long A[MAXN];

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) scanf("%d", B + i);

  int start = -1;
  REP(i, N) if (B[(i + 1) % N] > B[i]) { start = (i + 1) % N; break; }
  if (start == -1) {
    REP(i, N) if (B[i]) { printf("NO\n"); return 0; }
    printf("YES\n");
    REP(i, N) {
      if (i) printf(" ");
      printf("1");
    }
    printf("\n");
    return 0;
  }

  A[start] = B[start];
  REP(i, N - 1) {
    int x = (start + N - i) % N;
    int y = (x + N - 1) % N;
    int z = (y + N - 1) % N;
    A[y] = B[y] + A[x] * ((B[z] - B[y]) / A[x] + 1);
  }

  printf("YES\n");
  REP(i, N) {
    if (i) printf(" ");
    cout << A[i];
  }
  printf("\n");

  return 0;
}