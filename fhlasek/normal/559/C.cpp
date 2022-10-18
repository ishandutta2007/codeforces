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

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXC 211111
#define MOD 1000000007
int fac[MAXC], ifac[MAXC];

int power(int base, long long exponent) {
  int result = 1, m = base;
  while (exponent) {
    if (exponent & 1) result = ((long long)result * m) % MOD;
    m = ((long long)m * m) % MOD;
    exponent /= 2;
  }
  return result;
}

int c(int n, int k) { return (((long long)fac[n] * ifac[k])%MOD * ifac[n-k])%MOD; }

vector< pair<int, int> > b;
int ways[MAXC];

int main(int argc, char *argv[]) {

  fac[0] = 1;
  REP(i, MAXC) fac[i+1] = ((long long)fac[i]*(i+1))%MOD;
  ifac[MAXC-1] = power(fac[MAXC-1], MOD-2);
  FORD(i, MAXC-2, 0) ifac[i] = ((long long)ifac[i+1]*(i+1))%MOD;

  int N, M, B;
  scanf("%d%d%d", &N, &M, &B);
  REP(i, B) {
    int x, y;
    scanf("%d%d", &x, &y);
    b.push_back(make_pair(x - 1, y - 1));
  }

  sort(b.begin(), b.end());
  b.push_back(make_pair(N - 1, M - 1));
  B++;
  REP(i, B) {
    ways[i] = c(b[i].first + b[i].second, b[i].first);
    // printf("x: %d y: %d ways: %d\n", b[i].first, b[i].second, ways[i]);
    REP(j, i) if (b[i].first >= b[j].first && b[i].second >= b[j].second) {
      ways[i] = (ways[i] - (long long)ways[j] *
        c((b[i].first - b[j].first) + (b[i].second - b[j].second),
           b[i].first - b[j].first)) % MOD;
      if (ways[i] < 0) ways[i] += MOD;
    }
  }
  printf("%d\n", ways[B - 1]);
  return 0;
}