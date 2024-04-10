/* Written by Filip Hlasek 2013 */
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
int X[MAXN], Y[MAXN], Z[MAXN];
int N;
char t[MAXN];

int main(int argc, char *argv[]) {
  scanf("%s", t);
  N = strlen(t);
  REP(i, N) {
    X[i+1] = X[i]; Y[i+1] = Y[i]; Z[i+1] = Z[i];
    if (t[i] == 'x') X[i+1]++;
    if (t[i] == 'y') Y[i+1]++;
    if (t[i] == 'z') Z[i+1]++;
  }

  int Q;
  scanf("%d", &Q);
  while(Q--) {
    int L, R;
    scanf("%d%d", &L, &R);
    int x = X[R] - X[L-1], y = Y[R] - Y[L-1], z = Z[R] - Z[L-1];
    int m = min(x, min(y, z)), M = max(x, max(y, z));
    if (M - m <= 1 || R - L <= 1) printf("YES\n");
    else printf("NO\n");
  }
  
  return 0;
}