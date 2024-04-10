#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <stack>
#include <queue>
#include <vector>

#include <bitset>

#include <string>

#include <algorithm>
#include <functional>

#include <iostream>
#include <sstream>

using namespace std;
typedef long long llint;

#define pb push_back
#define MAXP 205
#define MAXN 100

int n;
int np[MAXP];

int a[MAXN];
int b[MAXN];
int dp[MAXN][1 << 10];

vector< int > p, pp;

int fm[MAXP];
int good[MAXP];

int fmask(int n) {
  int m = n;
  int mask = 0;
  for (int i = 0; i < p.size(); ++i) {
    if (n % p[i] == 0) {
      mask ^= (1 << i);
      while (n % p[i] == 0) n /= p[i];
    }
  }

  good[m] = (n == 1);

  return mask;
}

vector< int > sol[MAXN];

int brute(int pos, bool print = false) {
  int p = 30;
  int ret = 0;

  for (int i = pos; i < n; ++i) {
    while (np[p]) ++p;
    ret += abs(p - a[i]);
    if (print)
      sol[a[i]].pb(p);
    ++p;
  }

  return ret;
}

int solve(int pos, int mask) {
  if (pos == n) return 0;

  int &ref = dp[pos][mask];
  if (ref >= 0) return ref;
  ref = 1000000000;

  for (int i = 1; i <= 100; ++i) {
    if ((fm[i] & mask) != 0) continue;
    if (!good[i]) continue;
    ref = min(ref, solve(pos + 1, mask | fm[i]) + abs(i - a[pos]));
  }

  ref = min(ref, brute(pos));

  return ref;
}

void recon(int pos, int mask) {
  if (pos == n) return;

  for (int i = 1; i <= 100; ++i) {
    if ((fm[i] & mask) != 0) continue;
    if (!good[i]) continue;
    if (solve(pos, mask) == solve(pos + 1, mask | fm[i]) + abs(i - a[pos])) {
      sol[a[pos]].pb(i);
      recon(pos + 1, mask | fm[i]);
      return;
    }
  }

  brute(pos, true);
}



int main(void)
{ 
  for (int i = 2; i < MAXP; ++i) {
    if (np[i]) continue;
    for (int j = i + i; j < MAXP; j += i)
      np[j] = i;
  }

  for (int i = 2; i <= 30; ++i)
    if (!np[i]) p.push_back(i);

  for (int i = 2; i < MAXP; ++i)
    if (!np[i]) pp.push_back(i);

  for (int i = 1; i < MAXP; ++i) 
    fm[i] = fmask(i);

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    b[i] = a[i];
  }

  sort(a, a + n);

  memset(dp, -1, sizeof dp);
  recon(0, 0);

  for (int i = 0; i < n; ++i) {
    printf("%d ", sol[b[i]].back());
    sol[b[i]].pop_back();
  }
  puts("");

  return 0;
}