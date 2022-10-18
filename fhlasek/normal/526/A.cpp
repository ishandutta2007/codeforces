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

#define MAXN 111
int N;
char s[MAXN];

bool solve() {
  REP(start, N) FOR(len, 1, N) {
    bool ok = true;
    REP(i, 5) if (start + len * i >= N || s[start + len * i] == '.') { ok = false; break; }
    if (ok) return true;
  }
  return false;
}

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  scanf("%s", s);
  if (solve()) printf("yes\n");
  else printf("no\n");
  return 0;
}