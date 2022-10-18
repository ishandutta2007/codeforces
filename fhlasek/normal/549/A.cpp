/* Written by Filip Hlasek 2015 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 55
char m[MAXN][MAXN];

int main(int argc, char *argv[]) {
  int N, M;
  scanf("%d%d", &N, &M);
  REP(i, N) scanf("%s", m[i]);
  int ans = 0;
  REP(i, N - 1) REP(j, M - 1) {
    set<char> s;
    REP(d1, 2) REP(d2, 2) {
      char c = m[i + d1][j + d2];
      if (c == 'f' || c == 'a' || c == 'c' || c == 'e') s.insert(c);
    }
    ans += s.size() == 4;
  }
  printf("%d\n", ans);
  return 0;
}