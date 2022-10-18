#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <sstream>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

void fail() {
  puts("Impossible");
  exit(0);
}

string str(llint x) {
  stringstream ss;
  ss << x;
  return ss.str();
}

int main(void) 
{
  llint x, y;
  scanf("%lld%lld", &x, &y);

  string sol = "";

  for (;;) {
    if (x == y) fail();

    if (y == 1) {
      sol += str(x - 1) + "A";
      break;
    }

    if (x == 1) {
      sol += str(y - 1) + "B";
      break;
    }

    if (x > y) {
      if (y == 0) fail();
      llint k = x / y;
      x %= y;
      sol += str(k) + "A";
      continue;
    }

    if (y > x) {
      if (x == 0) fail();
      llint k = y / x;
      y %= x;
      sol += str(k) + "B";
      continue;
    }
  }

  printf("%s\n", sol.c_str());

  return 0;
}