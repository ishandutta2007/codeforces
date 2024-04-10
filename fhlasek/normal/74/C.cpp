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

inline int euclid(int a,int b){ return b ? euclid(b,a%b) : a; }

int main(int argc, char *argv[]){
  int N,M;
  scanf("%d%d",&N,&M);
  int n=min(N,M),m=max(N,M);
  printf("%d\n",euclid(N-1,M-1)+1);
  return 0;
}