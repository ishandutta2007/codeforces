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

int N;

int main(int argc, char *argv[]){
  scanf("%d",&N);
  int i,p=0;
  FOR(i,N-1){
    p=(p+i+1)%N;
    if(i<N-2) printf("%d ",p+1);
    else printf("%d\n",p+1);
  }
  return 0;
}