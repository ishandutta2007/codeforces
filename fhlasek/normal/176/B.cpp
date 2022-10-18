/* Writen by Filip Hlasek 2012 */
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
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

#define MOD 1000000007

char a[1111], b[1111];
int N,K;

int main(int argc, char *argv[]){
  scanf("%s",a); 
  scanf("%s",b);
  scanf("%d",&K);
  N = strlen(a);
  int a1 = 1, a2 = 0;
  REP(i,K){
    int tmp = a2;
    a2 = ((long long)a2 * (N-2) + a1) % MOD;
    a1 = ((long long)tmp * (N-1))%MOD;
  }
  int ans = 0;
  REP(i,N){
    bool ok = true;
    REP(j,N) if(a[j] != b[(i+j)%N]) ok = false;
    if(ok){
      if(!i) ans = (ans + a1)%MOD;
      else   ans = (ans + a2)%MOD;
    }
  }
  printf("%d\n",ans);
  return 0;
}