/* Writen by Filip Hlasek 2011 */
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

int N,M,A,B;

int get(){
  if(A==B) return 1;
  if(B==N) B=B-B%M+M;
  if((A-1)%M==0&&B%M==0) return 1;
  if((B-1)/M==(A-1)/M) return 1;
  if((B-A+1)%M==0) return 2;
  int res=3;
  if((B-1)/M-(A-1)/M>1){
    if((A-1)%M==0) res--;
    if(B%M==0) res--;
  }
  else return 2;
  return res;
}

int main(int argc, char *argv[]){
  scanf("%d%d%d%d",&N,&M,&A,&B); 
  printf("%d\n",get());
  return 0;
}