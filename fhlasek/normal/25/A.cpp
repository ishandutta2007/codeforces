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

int odd,even,o,e;

int main(int argc, char *argv[]){
  int N,i,j; 
  scanf("%d",&N);
  FOR(i,N){
    scanf("%d",&j);
    if(j%2==0){ even=i; e++; }
    else{ odd=i; o++; }
  }
  if(o==1) printf("%d\n",odd+1);
  else printf("%d\n",even+1);
  return 0;
}