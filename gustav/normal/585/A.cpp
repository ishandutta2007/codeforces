#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 4005;

int n;
llint v[MAXN];
llint p[MAXN];
llint d[MAXN];

int main(void) 
{
  scanf("%d", &n);
  REP(i, n) 
    scanf("%lld%lld%lld", v+i, d+i, p+i);

  vector< int > children;
  REP(i, n) children.push_back(i);

  vector< int > sol;

  while (!children.empty()) {
    int cc = children[0];
    children.erase(children.begin());
    sol.push_back(cc);

    REP(i, (int)children.size()) 
      p[children[i]] -= max(0LL, v[cc] - i);

    while (!children.empty()) {
      vector< int > kill;
      llint reduction = 0;

      REP(i, (int)children.size()) {
	if (p[children[i]] < 0) {
	  reduction += d[children[i]];
	  kill.push_back(i);
	} else {
	  p[children[i]] -= reduction;
	}
      }

      if (kill.empty())
	break;

      reverse(kill.begin(), kill.end());
      for (int i : kill) {
	children.erase(children.begin() + i);
      }
    }
  }

  printf("%d\n", (int)sol.size());
  REP(i, (int)sol.size())
    printf("%d%c", sol[i] + 1, " \n"[i + 1 == (int)sol.size()]);

  return 0;
}