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

const int MAXN = 200005;

int n;
int a[MAXN];
int sol[MAXN];

vector< pair< pair< int, int >, int > > gen(int m) {
  vector< pair< pair< int, int >, int > > ret;
  for (int k = 1; k * k <= m; ++k) {
    ret.push_back({{k, k}, m / k});
    if (m / k != k)
      ret.push_back({{m / (k + 1) + 1, m / k}, k});
  }
  return ret;
}

int main(void) 
{
  scanf("%d", &n);
  FOR(i, 1, n + 1) scanf("%d", a + i);

  for (int i = n; i >= 2; --i) {
    int m = i - 2;
    if (a[i] < a[1])
      ++sol[m + 1];
    auto intervals = gen(m);
    for (auto it : intervals) 
      if (a[i] < a[it.second + 1]) 
	++sol[it.first.first], --sol[it.first.second + 1];
  }
  
  llint cur = 0;
  FOR(k, 1, n) {
    cur += sol[k];
    printf("%lld ", cur);
  }
  puts("");

  return 0;
}