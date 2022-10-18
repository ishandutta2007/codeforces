#include <cstdio>
#include <cassert>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 30005;
int N, T;

int a[MAXN];
bool good[MAXN];

int main(void) 
{
  scanf("%d%d", &N, &T); --T;

  REP(i, N - 1) scanf("%d", a + i);

  good[T] = true;
  for (int i = T - 1; i >= 0; --i)
    if (good[i + a[i]])
      good[i] = true;

  if (good[0])
    puts("YES");
  else
    puts("NO");
  
  return 0;
}