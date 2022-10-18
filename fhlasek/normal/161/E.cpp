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

#define MAXN 111111
bool sieve[MAXN];

int N,m[6][6],posx[10],posy[10],POS,ans;

void gen(int pos){
  if(pos == POS){
    int add = 1;
    /*
    REP(i,N){
      REP(j,N) printf("%d",m[i][j]);
      printf("\n");
    }
    printf("\n");
    */
    FOR(i,1,N-1){
      int cnt = 0;
      REP(d,10){
        m[i][i] = d;
        int p = 0;
        REP(j,N) p = 10*p + m[i][j]; 
        cnt += !sieve[p];
      }
//      printf("cnt:%d\n",cnt);
      add *= cnt;
      if(!cnt) break;
    }
    ans += add;
    return;
  }
  REP(i,10){
    m[posx[pos]][posy[pos]] = m[posy[pos]][posx[pos]] = i;
    if(pos+1 == pos || posx[pos+1] != posx[pos]){
      int cnt = 0;
      REP(d,10){
        m[posx[pos]][posx[pos]] = d;
        int p = 0;
        REP(j,N) p = 10*p + m[posx[pos]][j]; 
        cnt += !sieve[p];
      }
      if(!cnt) continue;
    }
    gen(pos+1);
  }
}

int main(int argc, char *argv[]){
  sieve[0] = true;
  sieve[1] = true;
  FOR(i,2,MAXN-1) if(!sieve[i]) for(int j = 2*i; j < MAXN; j+=i) sieve[j] = true;
  int T = 0;
  char P[10];
  scanf("%d",&T);
  while(T--){
    scanf("%s",P);
    N = strlen(P);
    REP(i,N) m[i][0] = m[0][i] = P[i] - '0';
    POS = 0;
    FOR(i,1,N-1) FOR(j,i+1,N-1){
      posx[POS] = i;
      posy[POS] = j;
      POS++;
    }
    ans = 0;
    gen(0);
    printf("%d\n",ans);
  }
  return 0;
}