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

map<int, int> m;

#define MAXN 333
int N, L[MAXN], C[MAXN];
int M = 0;
vector<int> divisors;

void add_to_m(int val) {
  if (m.count(val)) return;
  divisors.push_back(val);
  m[val] = M++;
}

int dp[2][10000000];

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char *argv[]) {
  add_to_m(0);
  scanf("%d", &N);
  REP(i, N) scanf("%d", L + i);
  REP(i, N) scanf("%d", C + i);
  REP(i, N) {
    for (int j = 1; j * j <= L[i]; ++j) if (L[i] % j == 0) {
      add_to_m(j);
      add_to_m(L[i] / j);
    }
  }
  // REP(i, M) printf("i: %d divisor: %d\n", i, divisors[i]);
  dp[0][0] = 1;
  REP(i, N) {
    int act = i % 2, nact = 1 - act;
    REP(j, M) if (dp[act][j]) {
      int c = dp[act][j];
      dp[act][j] = 0;
      if (dp[nact][j] == 0 || dp[nact][j] > c) dp[nact][j] = c;
      int divisor = divisors[j];
      int jj = m[gcd(divisor, L[i])];
      c += C[i];
      if (dp[nact][jj] == 0 || dp[nact][jj] > c) dp[nact][jj] = c;
    }
  }

  int ans = dp[N % 2][m[1]] - 1;
  printf("%d\n", ans);
  return 0;
}