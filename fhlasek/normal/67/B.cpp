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
#define MAXN 1111

using namespace std;

int N,seq[MAXN],K;
bool done[MAXN];

int main(int argc, char *argv[]){
  int i,j,p;
  scanf("%d%d",&N,&K);
  FOR(i,N) scanf("%d",seq+i);
  FOR(i,N) done[i]=false;
  FOR(i,N){
    FOR(j,N) if(seq[j]==0&&!done[j]){ p=j; break; }
    if(i) printf(" ");
    printf("%d",p+1);
    done[p]=true;
    FOR(j,N) if(!done[j]&&j+K<=p) seq[j]--;
  }
  printf("\n");
  return 0;
}