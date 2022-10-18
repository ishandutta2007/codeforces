/* Written by Filip Hlasek 2014 */
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

#define MAXN 22
char v[MAXN], h[MAXN];

int main(int argc, char *argv[]) {
  int N, M;
  scanf("%d%d", &N, &M);
  scanf("%s", v); scanf("%s", h);
  if (v[0] == v[N - 1] || h[0] == h[M - 1] || (v[0] == '>' && h[0] == 'v') || (v[0] == '<' && h[0] == '^')) printf("NO\n");
  else printf("YES\n");
  return 0;
}