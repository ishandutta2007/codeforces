#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <ctime>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int MAX = 10000001;
const int MAXN = 500005;
const int mod = 1000000007;

inline int fmod(int n) { 
  return n >= mod ? n - mod : n;
}

int N;
int a[MAXN];
int s[MAX];
int z[MAX];
int mu[MAX];
int p2[MAXN];

int main(void) 
{
  scanf("%d", &N);
  REP(i, N) scanf("%d", a + i);
  REP(i, N) s[a[i]] += 1;

  p2[0] = 1;
  FOR(i, 1, MAXN) p2[i] = fmod(2 * p2[i - 1]);

  memset(mu, -1, sizeof mu);
  s[1] = 1;
  REP(j, N) z[1] = s[1] = fmod(2 * s[1]);
  mu[1] = 1;

  FOR(i, 2, MAX) {
    for (int j = 2 * i; j < MAX; j += i) {
      mu[j] -= mu[i];
      s[i] = s[i] + s[j];
    }
    s[i] = p2[s[i]] - 1;
  }

  int z1 = 0;
  for (int i = 1; i < MAX; ++i)
    z1 = ((llint)z1 + mod + mu[i] * s[i]) % mod;

  s[1] = fmod(s[1] + mod - z1);

  FOR(i, 1, MAX) {
    if (!mu[i]) continue;
    int add = fmod(mod + mu[i] * s[i]);
    for (int j = i; j < MAX; j += i)
      z[j] = fmod(z[j] + add);
  }

  int tot_sol = 0;
  REP(i, N) tot_sol = fmod(tot_sol + z[a[i]]);

  printf("%d\n", tot_sol);

  return 0;
}