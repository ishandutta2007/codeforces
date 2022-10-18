#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>

#define FOR(i,n) for(i=0;i<n;i++)
#define MAXN 1002

using namespace std;

int N,M;
char m[MAXN][MAXN];
int s[MAXN];
long long sum;

int main(int argc, char *argv[]){
  int i,j,tmp,tmp2;
  scanf("%d%d",&N,&M);
  FOR(i,N) scanf("%s",m[i]);
  sum=0;
  FOR(i,N) FOR(j,M){ if(m[i][j]=='*') s[j]++; }
  FOR(i,N){
    tmp=0;
    tmp2=0;
    FOR(j,M){
      if(m[i][j]=='*'){
        tmp++;
        tmp2+=s[j]-1;
      }
    }
    sum+=(long long)tmp2*(tmp-1);
  }
  printf("%lld\n",sum);
  return 0;
}