#include <cstdio>
#include <cstring>

#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int mod = 1e9 + 7;

int mul(int a, int b, int m) { return (llint)a * b % m; }

int power(int a, int b, int m) {
  int ret = 1;
  for (int i = 0; (1 << i) <= b; ++i) {
    if (((b >> i) & 1) == 1)
      ret = mul(ret, a, m);
    a = mul(a, a, m);
  }
  return ret;
}

void finish(int sol) {
  printf("%d\n", sol);
  exit(0);
}

int bio[1000005];

int main(void) 
{
  int p, k;
  scanf("%d%d", &p, &k);

  if (k == 0) finish(power(p, p - 1, mod));
  if (k == 1) finish(power(p, p, mod));

  int cnt = 0;
  FOR(i, 1, p) {
    if (bio[i]) continue;
    int j = i;
    while (!bio[j]) {
      bio[j] = 1;
      j = mul(j, k, p);
    }
    ++cnt;
  }

  finish(power(p, cnt, mod));

  return 0;
}