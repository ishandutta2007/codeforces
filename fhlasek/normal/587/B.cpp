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

#define MOD 1000000007
#define MAXN 2111111
int N, K;
long long L;
int A[MAXN];

int dp1[MAXN], dp2[MAXN];
int code(int k, int n) {
  return k * (N + 2) + n;
}

void add(int &x, long long add) {
  x = (x + add) % MOD;
}

map<int, int> m1, m2;
int val[MAXN];
int cnt[MAXN];

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  cin >> L;
  scanf("%d", &K);
  REP(i, N) scanf("%d", A + i);
  REP(i, N) m1[A[i]]++;
  int M = 0;
  for (map<int, int>::iterator it = m1.begin(); it != m1.end(); ++it) {
    val[M] = it->first;
    cnt[M++] = it->second;
  }
  REP(i, L % N) m2[A[i]]++;

  dp1[code(0, 0)] = 1;
  REP(k, K + 1) REP(m, M) {
    int c = code(k, m);
    add(dp2[c], dp1[c]);
    add(dp2[code(k, m + 1)], dp2[c]);
    add(dp1[code(k + 1, m)], (long long)cnt[m] * dp2[c]);
  }
  int ans = 0;
  FOR(k, 1, K) {
    add(ans, max(0LL, L / N - k + 1) % MOD * dp2[code(k, M - 1)]);
  }

  FORD(k, K, 1) {
    if (k > (L - 1) / N + 1) continue;
    REP(m, M) dp1[code(k, m)] = dp2[code(k, m)] = 0;
    REP(m, M) {
      add(dp1[code(k, m)], (long long)m2[val[m]] * dp2[code(k - 1, m)]);
    }
    REP(m, M) {
      int c = code(k, m);
      add(dp2[c], dp1[c]);
      add(dp2[code(k, m + 1)], dp2[c]);
    }
    add(ans, dp2[code(k, M - 1)]);
  }

  printf("%d\n", ans);
  return 0;
}