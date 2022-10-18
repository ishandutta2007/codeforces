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

long long lucky[2222];
int L;

void gen(long long x){
  if(x>MAX) return;
  lucky[L++]=x;
  gen(10*x+4);
  gen(10*x+7);
}

long long get(long long n){
  int i;
  long long sum=0;
  for(i=0;lucky[i]<n;i++){
//    printf("i:%d lucky[i+1]:%lld %lld\n",i,lucky[i+1],lucky[i]);
    sum+=lucky[i+1]*(min(n,lucky[i+1])-lucky[i]);
  }
  return sum; 
}

int main(int argc, char *argv[]){
  L=0;
  gen(0); 
  sort(lucky,lucky+L);
  int l,r;
  scanf("%d%d",&l,&r);
  cout << get(r)-get(l-1) << endl;
  return 0;
}