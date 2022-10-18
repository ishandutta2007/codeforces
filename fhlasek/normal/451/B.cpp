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

#define MAXN 111111
int a[MAXN], b[MAXN], N;

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) {
    scanf("%d", a + i);
    b[i] = a[i];
  }
  sort(b, b + N);
  int start = 0;
  while (start < N && a[start] == b[start]) ++start;
  if (start == N) { printf("yes\n1 1\n"); return 0; }
  int end = N - 1;
  while (a[end] == b[end]) --end;
  bool ok = true;
  REP(i, end - start) if (a[start + i] != b[end - i]) ok = false;
  // printf("start: %d end: %d\n", start, end);
  if (ok) printf("yes\n%d %d\n", start + 1, end + 1);
  else printf("no\n");
  return 0;
}