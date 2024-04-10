/* Written by Filip Hlasek 2015 */
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

int C, A, B, x, y;

long long best = 0;
void solve1() {
  for (int i = 0; (long long)A * i <= C && i < B; ++i) {
    int j = (C - (A * i)) / B;
    best = max(best, (long long)i * x + (long long)j * y);
  }
  for (int i = 0; (long long)B * i <= C && i < A; ++i) {
    int j = (C - (B * i)) / A;
    best = max(best, (long long)i * y + (long long)j * x);
  }
}

void solve2() {
  for (int i = 0; (long long)A * i <= C; ++i) {
    int j = (C - (A * i)) / B;
    best = max(best, (long long)i * x + (long long)j * y);
  }
}

int main(int argc, char *argv[]) {
  scanf("%d%d%d%d%d", &C, &x, &y, &A, &B);
  if (A < 1000 && B < 1000) solve1();
  else {
    if (A < B) { swap(A, B); swap(x, y); }
    solve2();
  }
  cout << best << endl;
  return 0;
}