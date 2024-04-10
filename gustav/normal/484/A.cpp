#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <stack>
#include <queue>
#include <vector>

#include <bitset>

#include <string>

#include <algorithm>
#include <functional>

#include <iostream>
#include <sstream>

using namespace std;
typedef unsigned long long llint;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

llint hibit(llint x) {
  if (x == 0) return 0;
  llint ret = 1;
  while (ret * 2 <= x) ret *= 2;
  return ret;
}

llint pc(llint l, llint r) {
  if (l == r) return l;
  if (r + 1 == ((r + 1) & -(r + 1))) return r;
  if (hibit(l) < hibit(r)) return hibit(r) - 1; 
  return hibit(l) + pc(l - hibit(l), r - hibit(r));
}

int main(void)
{
  int n;
  llint l, r;
  cin >> n;

  REP(i, n) {
    cin >> l >> r;
    cout << pc(l, r) << endl;
  }
  return 0;
}