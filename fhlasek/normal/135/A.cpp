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

int a[111111];
int main(int argc, char *argv[]){
  int N;
  scanf("%d",&N);
  REP(i,N) scanf("%d",a+i);
  sort(a,a+N);
  REP(i,N){
    if(i) printf(" ");
    if(i==N-1 && a[i] == 1) printf("2");
    else{
      if(i) printf("%d",a[i-1]);
      else  printf("1");
    }
  }
  printf("\n");
  return 0;
}