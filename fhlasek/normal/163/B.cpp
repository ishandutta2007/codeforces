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

int N,K,H;
int m[MAXN],v[MAXN],p[MAXN];
int ans[MAXN];

bool mycompare(int a,int b){
  if(m[a] != m[b]) return m[a] < m[b];
  return v[a] < v[b];
}

bool possible(double t){
  int pos = 0;
  REP(i,N) if((double)(pos+1)*H/v[p[i]] <= t) ans[pos++] = p[i];
  return pos >= K;
}

int main(int argc, char *argv[]){
  scanf("%d%d%d",&N,&K,&H);
  REP(i,N) scanf("%d",m+i);
  REP(i,N) scanf("%d",v+i);
  REP(i,N) p[i] = i;
  sort(p,p+N,mycompare);
  double left = 0, right = 1000000007, mid;
  REP(i,100){
    mid = (left + right)/2;
    if(possible(mid)) right = mid;
    else left = mid;
  }
  possible(right);
  REP(i,K){
    if(i) printf(" ");
    printf("%d",ans[i]+1);
  }
  printf("\n");
  return 0;
}