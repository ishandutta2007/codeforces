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

#define MAXN 111111
int M, N, A[MAXN];
set<int> a;

bool try_it(int d, int &x0) {
  int cur = *(a.begin());
  int n = 1;
  x0 = cur;
  while (n < N) {
    cur -= d;
    if (cur < 0) cur += M;
    if (a.find(cur) == a.end()) break;
    n++;
    x0 = cur;
  }
  cur = *(a.begin());
  while (n < N) {
    cur += d;
    if (cur >= M) cur -= M;
    if (a.find(cur) == a.end()) break;
    n++;
  }
  return n == N;
}

bool solve(int &x0, int &d) {
  vector<int> A(a.begin(), a.end());
  REP(i, N - 1) {
    d = (A[0] - A[i + 1] + M) % M;
    if (try_it(d, x0)) {
      return true;
    }
  }
  return false;
}


int main(int argc, char *argv[]) {
  scanf("%d%d", &M, &N);
  REP(i, N) scanf("%d", A + i);
  REP(i, N) a.insert(A[i]);

  if (N == 1) { printf("%d 1\n", A[0]); return 0; }

  if (N == M) { printf("1 1\n"); return 0; }

  if (N > M / 2) {
    set<int> b;
    REP(i, M) if (a.find(i) == a.end()) {
      b.insert(i);
    }
    a = b;
    int x0, d;
    N = M - N;
    if (N == 1) { x0 = *(a.begin()); d = 1; }
    else {
      if (!solve(x0, d)) {
        printf("-1\n");
        return 0;
      }
    }
    printf("%d %d\n", (int)((x0 + (long long)N * d) % M), d);
  }
  else {
    int x0, d;
    if (solve(x0, d)) printf("%d %d\n", x0, d);
    else printf("-1\n");
  }

  return 0;
}