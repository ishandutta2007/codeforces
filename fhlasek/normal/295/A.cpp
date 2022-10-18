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
int a[MAXN], b[MAXN];
int L[MAXN], R[MAXN], D[MAXN];
long long add[MAXN];

int main(int argc, char *argv[]){
  int N, M, K;
  scanf("%d%d%d", &N, &M, &K);
  REP(i, N) scanf("%d", a + i);
  REP(i, M) scanf("%d%d%d", L + i, R + i, D + i);
  while (K--) {
    int x, y;
    scanf("%d%d", &x, &y);
    b[x-1]++;
    b[y]--;
  }
  REP(i, M) {
    b[i+1] += b[i];
    add[L[i]-1] += (long long)D[i] * b[i];
    add[R[i]]   -= (long long)D[i] * b[i];
  }
  REP(i, N) {
    if(i) printf(" ");
    printf("%I64d", add[i] + a[i]);
    add[i+1] += add[i];
  }
  printf("\n");
  return 0;
}