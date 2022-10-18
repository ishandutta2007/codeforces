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

char s[111111];
int S,K;
int last[111111],L;
int bucket[27][111111],B[27];

void solve(){
  int pos = 0;
  while(true){
    REP(i,27) B[i] = 0;
    REP(i,L){
      if(last[i] + pos < S){
        int b = s[last[i] + pos] - 'a';
        bucket[b][B[b]++] = last[i];
      }
    }
    REP(i,27){
      long long sum = 0;
      REP(j,B[i]) sum += S-bucket[i][j]-pos;
      if(K>sum) K-=sum;
      else{
        L = 0;
        REP(j,B[i]) last[L++] = bucket[i][j];
        break;
      }
    }
    if(L>=K){ //end
      REP(i,pos+1) printf("%c",s[last[0]+i]);
      printf("\n");
      break;
    }
    K-=L;
    pos++;
  }
}

int main(int argc, char *argv[]){
  scanf("%s",s);
  S = strlen(s);
  scanf("%d",&K);
  if(K>(long long)S*(S+1)/2){ printf("No such line.\n"); return 0; }
  L = 0;
  REP(i,S) last[L++] = i;
  solve();
  return 0;
}