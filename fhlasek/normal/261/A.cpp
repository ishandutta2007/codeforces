/* Written by Filip Hlasek 2012 */
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
int a[MAXN];

int main(int argc, char *argv[]){
  int M, q, Q = MAXN, N;
  scanf("%d", &M);
  REP(i, M){ scanf("%d", &q); Q = min(Q, q); }
  scanf("%d", &N);
  REP(i, N) scanf("%d", a + i);
  sort(a, a + N);
  int ans = 0;
  int pos = N - 1;
  while(pos >= Q){
    REP(i, Q) ans += a[pos--];
    pos -= 2;
  }
  while(pos > -1) ans += a[pos--];
  printf("%d\n", ans);
  return 0;
}