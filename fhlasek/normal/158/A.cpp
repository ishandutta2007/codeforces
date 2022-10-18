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

int main(int argc, char *argv[]){
  int N,K,a[55]; 
  scanf("%d%d",&N,&K);
  REP(i,N) scanf("%d",a+i);
  int j = 0;
  if(a[K-1] == 0){
    while(a[j]) j++;
    printf("%d\n",j);
  }
  else{
    while(K + j <= N && a[K-1] == a[K+j]) j++;
    printf("%d\n",K+j);
  }
  return 0;
}