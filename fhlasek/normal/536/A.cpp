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

int A, B;

long long get_sum(int x) {
  if (x < 1) return 0;
  return (A + A + (long long)(x - 1) * B) * x / 2;
}

bool ok(long long l, long long r, int t, int m) {
  if (A + (r - 1) * B > t) return false;
  // if (r - l + 1 <= m) return true;
  return get_sum(r) - get_sum(l - 1) <= (long long)t * m;
}

int main(int argc, char *argv[]) {
  scanf("%d%d", &A, &B);
  int Q;
  scanf("%d", &Q);
  while (Q--) {
    int l, t, m;
    scanf("%d%d%d", &l, &t, &m);
    if (A + (long long)(l - 1) * B > t) {
      printf("-1\n");
      continue;
    }
    int L = l, R = 1000000;
    while (L < R) {
      int M = (L + R + 1) / 2;
      if (ok(l, M, t, m)) L = M;
      else R = M - 1;
    }
    cout << L << endl;
  }
  return 0;
}