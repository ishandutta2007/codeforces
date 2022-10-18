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

using namespace std;

int main(int argc, char *argv[]){
  int N,i,d[1000],a,b,res=0;
  scanf("%d",&N);
  FOR(i,N-1) scanf("%d",d+i);
  scanf("%d%d",&a,&b);
  for(;a<b;a++) res+=d[a-1];
  printf("%d\n",res);
  return 0;
}