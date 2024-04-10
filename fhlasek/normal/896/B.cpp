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

int N, M, C;

#define MAXN 1111
int A[MAXN];

bool is_done() {
  REP(i, N) if (A[i] == 0) return false;
  REP(i, N - 1) if (A[i + 1] < A[i]) return false;
  return true;
}

int place(int a) {
  if (a <= C / 2) {
    REP(i, N) if (A[i] == 0 || A[i] > a) return i;
  } else {
    FORD(i, N - 1, 0) if (A[i] == 0 || A[i] < a) return i;
  }
  return -1;
}

int main(int argc, char *argv[]) {
  scanf("%d%d%d", &N, &M, &C);
  while (true) {
    if (is_done()) break;
    int a;
    scanf("%d", &a);
    int ans = place(a);
    A[ans] = a;
    printf("%d\n", ans + 1);
    fflush(stdout);
  }
  
  return 0;
}