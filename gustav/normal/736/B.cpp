#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>

#include <sstream>
#include <iostream>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int MAX = 10000005;

void done(int x) {
  printf("%d\n", x);
  exit(0);
}

bool isprime(int n) {
  for (llint i = 2; i * i <= n; ++i)
    if (n % i == 0)
      return false;
  return true;
}


int main(void) 
{
  int n;
  scanf("%d", &n);

  if (isprime(n)) done(1);
  if (n % 2 == 0 || isprime(n - 2)) done(2);
  done(3);

  return 0;
}