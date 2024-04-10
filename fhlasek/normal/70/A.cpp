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
#define MOD 1000003

using namespace std;

int N;

int main(int argc, char *argv[]){
  scanf("%d",&N); 
  if(N==0){ printf("%d\n",1); return 0; }
  int i,res=1;
  FOR(i,N-1) res=(res*3)%MOD;
  printf("%d\n",res);
  return 0;
}