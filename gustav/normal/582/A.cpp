#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <cassert>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

int main(void) 
{
  int n;
  scanf("%d", &n);

  multiset< int > s;
  REP(i, n * n) {
    int x;
    scanf("%d", &x);
    s.insert(x);
  }

  vector< int > sol;

  while (sol.size() < n) {
    int nxt = *--s.end();
    s.erase(s.find(nxt));
    for (int i : sol) {
      s.erase(s.find(__gcd(i, nxt)));
      s.erase(s.find(__gcd(i, nxt)));
    }
    sol.push_back(nxt);
  }

  REP(i, n)
    printf("%d%c", sol[i], " \n"[i+1==n]);

  return 0;
}