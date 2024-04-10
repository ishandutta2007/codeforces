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
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 222
int N, a[MAXN][MAXN], _K[MAXN], K[MAXN], C[MAXN];

int main(int argc, char *argv[]){
  int best = 1000000000, cur;
  scanf("%d",&N);
  REP(i,N){
    scanf("%d",C+i);
    C[i]--;
  }
  REP(i,N){
    scanf("%d",_K+i);
    REP(j, _K[i]){
      scanf("%d",&(a[i][j]));
      a[i][j]--;
    }
  }

  queue<int> q[3];
  REP(start,3){
    int pos = start, rem = N;
    cur = N-1;
    REP(i,N) K[i] = _K[i];
    REP(i,N) if(!K[i]) q[C[i]].push(i);
    while(rem){
      pos = (pos + 1) % 3;
      cur++;
      while(!q[pos].empty()){
        int x = q[pos].front();
        q[pos].pop();
        rem--;
        REP(j,N) REP(l,_K[j]) if(a[j][l] == x){
          K[j]--;
          if(K[j] == 0){
            q[C[j]].push(j);
            K[j]--;
          }
        }
      }
    }
    best = min(best, cur);
  }
  printf("%d\n", best);
  return 0;
}