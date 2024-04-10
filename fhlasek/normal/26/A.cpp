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
#define MAXN 31000

using namespace std;
int sieve[MAXN],primes[MAXN],P,a[MAXN];

void p(){
  int i,j,ii,jj;
  P=0;
  sieve[0]=1;
  sieve[1]=1;
  for(i=2;i<MAXN;i++){
    if(sieve[i]==0){
      primes[P++]=i;
      for(j=2*i;j<MAXN;j+=i) sieve[j]=1;
    }
  }
  FOR(i,P){
    ii=primes[i];
    while(2*ii<MAXN){
      for(j=i+1;j<P;j++){
        if(ii*primes[j]>=MAXN) break;
        jj=primes[j];
        while(ii*jj<MAXN){
          a[ii*jj]=1;
          jj*=primes[j];
        }
      }
      ii*=primes[i];
    }
  }
}

int main(int argc, char *argv[]){
  int N,i,sum=0;
  scanf("%d",&N);
  p();
  FOR(i,N+1) sum+=a[i];
  printf("%d\n",sum);
  return 0;
}