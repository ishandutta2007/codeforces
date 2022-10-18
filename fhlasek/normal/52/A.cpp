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

int a[3]; 
int main(int argc, char *argv[]){
  int N,i,x;
  scanf("%d",&N);
  FOR(i,N){
    scanf("%d",&x);
    a[x-1]++;
  }
  x=max(a[0],a[1]);
  x=max(x,a[2]);
  printf("%d\n",N-x);
  return 0;
}