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
#define MAXN 10000

using namespace std;

int seq[MAXN],N;

bool right(int r){
  for(++r;r<N;r++){
    if(seq[r]!=seq[r-1]+1) return false;
  }
  return true;
}

bool left(int l){
  int r;
  for(r=l+1;r<=N;r++){
    if(r==N||seq[r]+1!=seq[r-1]){
      if(seq[r-1]!=l+1) break;
      if(right(r)){
        printf("%d %d\n",l+1,r);
        return true;
      }
      break;
    }
  }
  return false;
}

int main(int argc, char *argv[]){
  int i;
  scanf("%d",&N);
  FOR(i,N) scanf("%d",seq+i);
  FOR(i,N){
    if(seq[i]!=i+1){
      if(left(i)) return 0;
      break;
    }
  }
  printf("0 0\n");
  return 0;
}