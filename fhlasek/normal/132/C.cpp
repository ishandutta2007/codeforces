/* Writen by Filip Hlasek 2011 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

char line[111];
int L,N;

bool pos[101][55][203][2];

int main(int argc, char *argv[]){
  scanf("%s",line);
  L=strlen(line);
  scanf("%d",&N);
  pos[0][0][101][0]=true;
  FOR(i,1,L){
    FOR(n,0,N){
      FOR(p,0,202){
        FOR(w,0,1){
          FOR(nn,0,n){
            if((line[i-1]=='F'&&(nn&1)==0)||(line[i-1]=='T'&&(nn&1)==1)){ if(pos[i-1][n-nn][p-(2*w)+1][w]){ pos[i][n][p][w]=true; break; }}
            else if(pos[i-1][n-nn][p][1-w]){ pos[i][n][p][w]=true; break; }
          }
        }
      }
    }
  }
  int res=0;
  FOR(p,0,202) if(pos[L][N][p][0]||pos[L][N][p][1]) res=max(res,abs(101-p));
  printf("%d\n",res);
  return 0;
}