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

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

#define MAXN 111
#define BEFORE 350
#define AFTER  360

int N,a[MAXN],solved=0,T=0,sum=0;

int main(int argc, char *argv[]){
  scanf("%d",&N);   
  REP(i,N) scanf("%d",a+i);
  sort(a,a+N);
  REP(i,N){
    sum+=a[i];
    if(sum>BEFORE+AFTER) break;
    solved++;
    if(sum>BEFORE) T+=sum-BEFORE;
  }
  printf("%d %d\n",solved,T);
  return 0;
}