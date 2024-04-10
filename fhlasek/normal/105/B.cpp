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

int N,K,A,b[10],l[10],bribe[10];
double best,nl[10];

void getprob(){
  int i,j,sum,B;
  double prob=1,final=0;
  FOR(i,1<<N){
    sum=0;
    prob=1;
    B=0;
    FOR(j,N){
      if(i&(1<<j)){
        prob*=nl[j];
        sum++;
      }
      else{
        B+=b[j];
        prob*=1-nl[j];
      }
    }
    //printf("i:%d final:%lf prob:%lf sum:%d\n",i,final,prob,sum);
    if(sum>N/2) final+=prob;
    else final+=prob*A/(A+B);
    //printf("i:%d final:%lf\n",i,final);
  }
  //printf("%lf, final:%lf\n",nl[0],final);
  best=max(best,final);
}

void go(int n,int k){
  if(n==N){
    int i;
    FOR(i,N) nl[i]=(double)min(100,l[i]+10*bribe[i])/100;
    getprob();
    return;
  }
  go(n+1,k);
  if(k){
    bribe[n]++;
    go(n,k-1);
    bribe[n]--;
  }
}

int main(int argc, char *argv[]){
  scanf("%d%d%d",&N,&K,&A); 
  int i;
  FOR(i,N) scanf("%d%d",b+i,l+i);
  best=0;
  go(0,K);
  printf("%.9lf\n",best);
  return 0;
}