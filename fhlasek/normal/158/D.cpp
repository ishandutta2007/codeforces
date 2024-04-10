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

#define MAXN 111111
int t[MAXN],N;

int main(int argc, char *argv[]){
  int best = -MAXN * 1000;
  scanf("%d",&N);
  REP(i,N) scanf("%d",t+i);
  FOR(d,3,N) if(N%d == 0) REP(start,N/d){
    int sum = 0;
    REP(i,d) sum += t[start + N/d * i];
    best = max(sum,best);
  }
  printf("%d\n",best);
  return 0;
}