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

long long n, k, d1, d2;

bool solve(long long x2, long long x3) {
  // 3 * x + x2 + x3 = k
  if ((k - x2 - x3) % 3) return false;
  long long x = (k - x2 - x3) / 3;
  if (x < 0 || x > n / 3 || x + x2 < 0 || x + x2 > n / 3 || x + x3 < 0 || x + x3 > n / 3) return false;
  return true;
}

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  while (T--) {
    cin >> n >> k >> d1 >> d2;
    if (n % 3) { printf("no\n"); continue; }
    if (solve(d1, d1 + d2) || solve(d1, d1 - d2) || solve(-d1, -d1 + d2) || solve(-d1, -d1 -d2)) printf("yes\n");
    else printf("no\n");
  }
  return 0;
}