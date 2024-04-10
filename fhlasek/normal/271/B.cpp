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

bool is_prime(int x){
  if(x < 2) return false;
  for(int i = 2; i * i <= x; i++) if(x % i == 0) return false;
  return true;
}

#define MAXN 111111
int next_prime[MAXN];

#define MAX 555
int m[MAX][MAX];

int main(int argc, char *argv[]){
  FORD(i, MAXN-2, 0) if(is_prime(i)) next_prime[i] = i; else next_prime[i] = next_prime[i+1];
  int N, M;
  int best = MAX * MAXN;
  scanf("%d%d", &N, &M);
  REP(i, N) REP(j, M) scanf("%d", &(m[i][j]));

  REP(i, N) {
    int tmp = 0;
    REP(j, M) tmp += next_prime[m[i][j]] - m[i][j]; 
    best = min(tmp, best);
  }
  
  REP(j, M) {
    int tmp = 0;
    REP(i, N) tmp += next_prime[m[i][j]] - m[i][j]; 
    best = min(tmp, best);
  }

  printf("%d\n", best);
   
  return 0;
}