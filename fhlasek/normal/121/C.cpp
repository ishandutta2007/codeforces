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
#include <iostream>

#define FOR(i,n) for(i=0;i<n;i++)
#define MAX 5000000000LL

using namespace std;

long long lucky[2222],fac;
int L,N,K;
int p[100];
bool pos[100];

void gen(long long x){
  if(x>MAX) return;
  if(x) lucky[L++]=x;
  gen(10*x+4);
  gen(10*x+7);
}

bool islucky(long long a){
  while(a){ if(a%10!=4&&a%10!=7) return false; a/=10; }
  return true;
}

void permutation(int n,int k){
  int i,j,l;
/*  FOR(i,n) p[i]=i;
  FOR(i,k-1) next_permutation(p,p+n);*/
  k--;
  FOR(i,n){
    fac/=n-i;    
    j=k/fac;
    FOR(l,n) if(!pos[l]){ j--; if(j<0) break; }
    p[i]=l;
    pos[l]=true;
    k%=fac;
  }
}

int main(int argc, char *argv[]){
  L=0;
  gen(0); 
  sort(lucky,lucky+L);
  scanf("%d%d",&N,&K);
  int i=0,sum,I;
  fac=1;
  while(fac<K) fac*=++i;
  if(i>N){ printf("-1\n"); return 0; }
  I=i;
  FOR(i,L) if(lucky[i]>N-I) break;
  sum=i;
  permutation(I,K);
  FOR(i,I) if(islucky(p[i]+N-I+1)&&islucky(N-I+1+i)) sum++;
  printf("%d\n",sum);
  return 0;
}