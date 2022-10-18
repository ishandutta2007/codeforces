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

const int NORTH = 0;
const int SOUTH = 20000;

void no() {
  puts("NO");
  exit(0);
}

void yes() {
  puts("YES");
  exit(0);
}

int main(void) 
{
  int n;
  cin >> n;

  int pos = 0;

  REP(i, n) {
    int x;
    string dir;
    cin >> x >> dir;

    if ((pos == NORTH || pos == SOUTH) &&
	(dir == "East" || dir == "West"))
      no();

    if (dir == "North")
      pos -= x;
    if (dir == "South")
      pos += x;

    if (pos < NORTH || pos > SOUTH)
      no();
  }

  if (pos) no();
  yes();

  return 0;
}