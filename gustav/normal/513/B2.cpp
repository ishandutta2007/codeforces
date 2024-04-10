#include <cstdio>
#include <cassert>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 55;
typedef long long llint;

int p[MAXN];

vector< int > gen(int n, llint m) {
  if (n == 1) return { 1 };

  vector< int > v;

  if (m <= (1LL << (n - 2))) {
    v = gen(n - 1, m);
    REP(i, n - 1) ++v[i];
    v.insert(v.begin(), 1);
    return v;
  } else {
    v = gen(n - 1, m - (1LL << (n - 2)));
    REP(i, n - 1) ++v[i];
    v.push_back(1);
    return v;
  }
}

int main(void) 
{
  int n;
  llint m;
  scanf("%d%I64d", &n, &m);

  vector< int > v = gen(n, m);

  REP(i, n) printf("%d ", v[i]);
  puts("");

  return 0;
}