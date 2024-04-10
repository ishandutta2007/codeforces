#include <cstdio>
#include <cstring>

#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <stack>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 100005;

int N, Q;
int a[MAXN];
int d[MAXN];
int L[MAXN];
int R[MAXN];

llint solve(int *a, int n) {
  REP(i, n - 1) d[i] = abs(a[i + 1] - a[i]);

  stack< int > stk;
  REP(i, n - 1) {
    while (!stk.empty() && d[stk.top()] < d[i]) stk.pop();

    if (!stk.empty())
      L[i] = stk.top();
    else
      L[i] = -1;

    stk.push(i);
  }

  while (!stk.empty()) stk.pop();
  for (int i = n - 2; i >= 0; --i) {
    while (!stk.empty() && d[stk.top()] <= d[i]) stk.pop();

    if (!stk.empty())
      R[i] = stk.top();
    else
      R[i] = n - 1;

    stk.push(i);
  }

  llint sol = 0;
  REP(i, n - 1)
    sol += (llint)(i - L[i]) * (R[i] - i) * d[i];

  return sol;
}

int main(void) 
{
  scanf("%d%d", &N, &Q);
  REP(i, N) scanf("%d", a + i);

  REP(i, Q) {
    int l, r;
    scanf("%d%d", &l, &r); 
    --l; --r;
    printf("%lld\n", solve(a + l, r - l + 1));
  }

  return 0;
}