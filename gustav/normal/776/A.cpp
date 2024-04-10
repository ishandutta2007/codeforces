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


int main(void) 
{
  string a, b;
  cin >> a >> b;
  int n;
  cin >> n;

  cout << a << " " << b << endl;

  REP(i, n) {
    string x, y;
    cin >> x >> y;
    if (a == x) {
      a = y;
    } else {
      b = y;
    }
    cout << a << " " << b << endl;
  }
  return 0;
}