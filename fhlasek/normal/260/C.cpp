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
long long a[MAXN];

int main(int argc, char *argv[]){
  int N, X; 
  scanf("%d%d", &N, &X);
  X--;
  REP(i, N) scanf("%d", a + i);
  int start = (X + 1) % N;
  FOR(i, 1, N) if(a[start] >= a[(X + i) % N]) start = (X + i) % N;
  long long add = 0;
  int t = a[start];
  if(start <= X){
    REP(i, start+1){ a[i] -= t; add += t; }
    FOR(i, X+1, N-1){ a[i] -= t; add += t; }
    FOR(i, start+1, X){ a[i] -= t+1; add += t+1; }
  }
  else{
    REP(i, X+1){ a[i] -= t+1; add += t+1; }
    FOR(i, X+1, start){ a[i] -= t; add += t; }
    FOR(i, start+1, N-1){ a[i] -= t+1; add += t+1; }
  }
  a[start] = add;
  REP(i, N){
    if(i) printf(" ");
    printf("%I64d", a[i]);
  }
  printf("\n");
  return 0;
}