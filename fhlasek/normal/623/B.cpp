/* Written by Filip Hlasek 2016 */
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

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

#define MAXN 1111111
int N, A, B, a[MAXN];
int t[MAXN];

long long solve(int p) {
  bool all = true;
  REP(i, N) {
    if (a[i] % p == 0) t[i] = 0;
    else if ((a[i] + 1) % p == 0 || (a[i] - 1) % p == 0) t[i] = 1;
    else { t[i] = 2; all = false; }
  }
  if (all) {
    long long dp0 = 0, dp1 = 0, dp2 = 0;
    REP(i, N) {
      dp0 = dp0 + B * t[i];
      dp1 = min(A + dp1, dp0);
      dp2 = min(dp2 + B * t[i], dp1);
    }
    return dp2;
  }
  else {
    int sum = 0;
    long long best_start = 0;
    long long best_end   = 0;
    REP(i, N) {
      if (t[i] == 2) break;
      sum += t[i];
      best_start = min(best_start, (long long)sum * B - (long long)(i + 1) * A);
    }
    sum = 0;
    REP(i, N) {
      if (t[N - i - 1] == 2) break;
      sum += t[N - i - 1];
      best_end = min(best_end, (long long)sum * B - (long long)(i + 1) * A);
    }
    return (long long)A * N + best_start + best_end;
  }
}

long long solve() {
  long long ans = MAXN * (long long)(A + B);
  FOR(dx, -1, 1) {
    int x = a[0] + dx;
    for (int p = 2; p * p <= x; ++p) if (x % p == 0) {
      while (x % p == 0) x /= p;
      ans = min(ans, solve(p));
    }
    if (x > 1) ans = min(ans, solve(x));
  }
  return ans;
}

int main(int argc, char *argv[]) {
  scanf("%d%d%d", &N, &A, &B);
  REP(i, N) scanf("%d", a + i);

  long long ans = solve();
  reverse(a, a + N);
  ans = min(ans, solve());
  cout << ans << endl;
  return 0;
}