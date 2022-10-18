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

#define MAXN 1111
int a[MAXN][MAXN];
long long d[MAXN][MAXN];

int main(int argc, char *argv[]){
  int N, M, K; 
  scanf("%d%d%d", &N, &M, &K);
  int besta = K-1, bestb=1;
  long long best = -1; 
  REP(i, N) REP(j, M) scanf("%d", &(a[i][j]));
  FOR(i, K-1, N-K){
    REP(j, M) d[j][0] = a[i][j];
    FOR(k, 1, K-1) FOR(j, k, M-k-1) d[j][k] = d[j-1][k-1] + d[j+1][k-1] - d[j][max(0, k-2)] + (long long)a[i-k+1][j] + (long long)a[i-k][j] + (long long)a[i+k-1][j] + (long long)a[i+k][j];
    FOR(j, K-1, M-K){
      long long sum = 0;
      REP(k, K) sum += d[j][k];
      if(sum > best){ best = sum; besta = i; bestb = j; }
    }
  }

  printf("%d %d\n", besta+1, bestb+1);
  return 0;
}