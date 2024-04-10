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

#define MAXN 1111
char a[MAXN],b[MAXN];
int A,B;
int S1=0,S2=0;
int ans1=0,ans2=0;
int N;

int E1,E2;
void eval(char x,char y){
  E1 = E2 = 0;
  if(x == 'R'){
    if(y == 'P') E1 = 1;
    if(y == 'S') E2 = 1;
  }
  if(x == 'P'){
    if(y == 'S') E1 = 1;
    if(y == 'R') E2 = 1;
  }
  if(x == 'S'){
    if(y == 'R') E1 = 1;
    if(y == 'P') E2 = 1;
  }
}

int main(int argc, char *argv[]){
  scanf("%d",&N);
  scanf("%s",a);   
  A = strlen(a);
  scanf("%s",b);
  B = strlen(b);
  REP(i,A*B){
    eval(a[i%A],b[i%B]);
    S1 += E1;
    S2 += E2;
  }
  ans1 = S1 * (N/(A*B));
  ans2 = S2 * (N/(A*B));
  N %= A*B;
  REP(i,N){
    eval(a[i%A],b[i%B]);
    ans1 += E1;
    ans2 += E2;
  }
  printf("%d %d\n",ans1,ans2);
  return 0;
}