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
  int N,L,a[200],i,l;
  scanf("%d%d",&N,&L);
  FOR(i,N) scanf("%d",a+i);
  int maximum=0,c;
  for(l=L;l<100;l++){
    c=0;
    FOR(i,N) c+=a[i]/l;
    maximum=max(maximum,c*l);
  }
  printf("%d\n",maximum);
  return 0;
}