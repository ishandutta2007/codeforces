#include <cstdio>
#include <cassert>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long double ld;
typedef long long llint;

ld sq(ld x) { return x * x; }

int main(void) 
{
  llint n;
  cin >> n;

  vector< llint > sol;

  for (int k = 0; (1LL << k) <= n + 1; ++k) {
    ld c = (1LL << k) - 1.0;

    ld x0 = -(c - 0.5) + sqrt(sq(c - 0.5) + 2.0 * n);
    llint x = round(x0);

    if ((x << k) - x + x * (x - 1) / 2 == n && x % 2 == 1)
      sol.push_back(x << k);
  }

  sort(sol.begin(), sol.end());

  if ((int)sol.size() == 0)
    cout << "-1" << endl;
  else 
    for (llint i : sol) cout << i << endl;

  return 0;
}