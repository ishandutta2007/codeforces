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

bool m[111][111];
int cnt[111],group[111],G;

int main(int argc, char *argv[]){
  int N,M,a,b;
  scanf("%d%d",&N,&M);
  REP(i,M){
    scanf("%d%d",&a,&b);
    m[a-1][b-1] = true;
    m[b-1][a-1] = true;
    cnt[a-1]++;
    cnt[b-1]++;
  }
  int res = 0;
  while(true){
    G = 0;
    REP(i,N) if(cnt[i] == 1) group[G++]=i;
    if(!G) break;
    res++;
    REP(i,G){
      cnt[group[i]] = 0;
      REP(j,N) if(m[group[i]][j]) cnt[j]--;
    }
  }
  printf("%d\n",res);
  return 0;
}