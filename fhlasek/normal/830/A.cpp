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

#define MAXN 3333
int N, K, P;
int a[MAXN], b[MAXN];

bool possible(int t) {
  int k = 0;
  REP(i, N) {
    while (k < K && abs(a[i] - b[k]) + abs(b[k] - P) > t) k++;
    if (k == K) return false;
    k++;
  }
  return true;
}

int main(int argc, char *argv[]) {
  scanf("%d%d%d", &N, &K, &P);
  REP(i, N) scanf("%d", a + i);
  REP(i, K) scanf("%d", b + i);
  sort(a, a + N);
  sort(b, b + K);
  int l = 0, r = 2000000000;
  while (l < r) {
    int m = ((long long)l + r) / 2;
    if (possible(m)) r = m;
    else l = m + 1;
  }
  printf("%d\n", l);
  return 0;
}