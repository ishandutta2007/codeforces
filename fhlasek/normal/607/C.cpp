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

#define MAXN 2111111
char a[MAXN], b[MAXN];
int N;

int M;
char needle[MAXN];
int fail[MAXN];

void failure() { //precomputes the failure function
  int k;
  fail[0] = -1;
  FOR(i, 1, M) {
    for (k = fail[i - 1]; k >= 0 && needle[k] != needle[i - 1]; k = fail[k]) ;
    fail[i] = k + 1;
  }
}

int main(int argc, char *argv[]) {
  scanf("%d", &N); N--;
  scanf("%s", a);
  scanf("%s", b);
  M = 2 * N;
  REP(i, N) needle[N + i] = a[i];
  REP(i, N) {
    int pos = N - i - 1;
    char c = b[i];
    if (c == 'N') c = 'S';
    else if (c == 'S') c = 'N';
    else if (c == 'W') c = 'E';
    else if (c == 'E') c = 'W';
    needle[pos] = c;
  }
  failure();
  if (fail[M]) printf("NO\n");
  else printf("YES\n");
  return 0;
}