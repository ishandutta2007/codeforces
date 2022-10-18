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

#define MAXN 1111111
char a[MAXN], b[MAXN];
vector<int> diff;

int main(int argc, char *argv[]) {
  scanf("%s", a);
  scanf("%s", b);
  int N = strlen(a);
  REP(i, N) if (a[i] != b[i]) diff.push_back(i);
  if (diff.size() % 2) printf("impossible\n");
  else {
    REP(i, diff.size()) if (i % 2) a[diff[i]] = b[diff[i]];
    printf("%s\n", a);
  }
  return 0;
}