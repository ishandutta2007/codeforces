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

int N,L,V1,V2,a[MAXN];
double L1;
double ans[MAXN];

int main(int argc, char *argv[]){
  scanf("%d%d%d%d",&N,&L,&V1,&V2);
  REP(i,N) scanf("%d",a+i+1);
  double L1 = (double)L*V2/(V2+V1);
  int ch = 0,pos = 0;
  double l = a[1];
  a[N+1] = 2*L;
  while(a[pos+1] < L1){
    l += a[(pos+1)%N+1] - a[pos+1];
    pos = (pos+1)%N;
    if(!pos) l += 2*L;
    ch++;
    if(!pos) break;
  }
  REP(i,N+1){
    double start = a[i] + L1, end = a[i+1] + L1;
    while(l <= end){
      ans[ch] += (l-start)/(2*L);
      start = l;
      ch++;
      l += a[(pos+1)%N+1] - a[pos+1];
      pos = (pos+1)%N;
      if(!pos) l += 2*L;
    }
    ans[ch] += (end-start)/(2*L);
    ch--;    
  }
  REP(i,N+1) printf("%.15lf\n",ans[i]);
  return 0;
}