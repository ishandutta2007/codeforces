/* Writen by Filip Hlasek 2012 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

#define MOD 1000000007

int power(int base, int exponent){
  int result = 1, m = base;
  REP(i,31){
    if(exponent&(1<<i)) result = ((long long)result*m)%MOD;
    m = ((long long)m*m)%MOD;
  }
  return result;
}

int N,M,K;

int main(int argc, char *argv[]){
  scanf("%d%d%d",&N,&M,&K);
  if(K>N || K == 1){
    printf("%d\n",power(M,N));
    return 0;
  }
  if(K == N){
    printf("%d\n",power(M,(N+1)/2));
    return 0;
  }
  if(K%2 == 0) printf("%d\n",M);
  else printf("%d\n",M*M);
  return 0;
}