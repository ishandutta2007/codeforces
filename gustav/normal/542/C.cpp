#include <cstdio>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

llint gcd(llint a, llint b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

llint lcm(llint a, llint b) {
  return a / gcd(a, b) * b;
}

const int MAXN = 205;

int n;
int f[MAXN];
int F[MAXN];
int g[MAXN];
bool cycle[MAXN];
bool bio[MAXN];

vector< int > cycles;

bool check() {
  REP(i, n) {
    int j = F[i];
    cycle[i] = false;
    REP(k, n) {
      j = F[j];
      if (j == i) 
	cycle[i] = true;
    }
  }

  cycles.clear();

  REP(i, n) bio[i] = false;
  REP(i, n) {
    if (!cycle[i]) continue;
    if (bio[i]) continue;
    bio[i] = true;
    int j = F[i];
    int cnt = 1;
    while (j != i) {
      bio[j] = true;
      j = F[j];
      ++cnt;
    }
    cycles.push_back(cnt);
  }

  REP(i, n)
    if (!cycle[i] && !cycle[F[i]])
      return false;

  return true;
}

int main(void) 
{
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d", &f[i]);
    --f[i];
  }

  REP(i, n) F[i] = f[i];

  check();
  llint L = cycles[0];
  for (int x : cycles)
    L = lcm(L, x);

  llint cnt = 1;
  while (!check()) {
    REP(i, n) g[i] = f[F[i]];
    REP(i, n) F[i] = g[i];
    ++cnt;
  }

  //  TRACE(cnt);

  llint sol = L;
  while (sol < cnt) sol += L;

  printf("%lld\n", sol);

  return 0;
}