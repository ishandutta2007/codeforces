/* Written by Filip Hlasek 2018 */
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

set<int> stairs, elevators;

int N, M, V;

int main(int argc, char* argv[]) {
  scanf("%d%d", &N, &M);
  int S, E;
  scanf("%d%d%d", &S, &E, &V);
  REP(i, S) {
    int s;
    scanf("%d", &s);
    stairs.insert(s);
  }
  REP(i, E) {
    int e;
    scanf("%d", &e);
    elevators.insert(e);
  }
  int Q;
  scanf("%d", &Q);
  while (Q--) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

    int ans = 2 * (N + M);

    if (x1 == x2) ans = abs(y1 - y2);

    // Use stairs
    auto s = stairs.lower_bound(y1);
    if (s != stairs.end()) {
      ans = min(ans, abs(x1 - x2) + abs(y1 - *s) + abs(*s - y2));
    }
    if (s != stairs.begin()) {
      --s;
      ans = min(ans, abs(x1 - x2) + abs(y1 - *s) + abs(*s - y2));
    }

    // Use elevators
    auto e = elevators.lower_bound(y1);
    int steps = (abs(x1 - x2) + V - 1) / V;
    if (e != elevators.end()) {
      ans = min(ans, steps + abs(y1 - *e) + abs(*e - y2));
    }
    if (e != elevators.begin()) {
      --e;
      ans = min(ans, steps + abs(y1 - *e) + abs(*e - y2));
    }

    printf("%d\n", ans);
  }

  return 0;
}