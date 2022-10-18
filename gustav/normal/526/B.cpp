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

const int MAXN = 11;
const int MAX = 1 << (MAXN + 1);

int a[MAX];
int cnt[MAX];

int main(void) 
{
  int n; scanf("%d", &n);

  FOR(i, 2, (1 << (n + 1)))
    scanf("%d", a + i);

  FOR(i, 1 << n, 1 << (n + 1))
    cnt[i] = a[i];

  int sol = 0;
  for (int i = (1 << n) - 1; i >= 1; --i) {
    int l = 2 * i;
    int r = 2 * i + 1;
    sol += abs(cnt[l] - cnt[r]);
    cnt[i] = max(cnt[l], cnt[r]) + a[i];
  }

  printf("%d\n", sol);

  return 0;
}