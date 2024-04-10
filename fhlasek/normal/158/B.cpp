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

int a[5];

int main(int argc, char *argv[]){
  int N,s,ans=0; 
  scanf("%d",&N);
  REP(i,N){
    scanf("%d",&s);
    a[s]++;
  }
  ans += a[4];
  ans += a[3];
  a[1] = max(0,a[1] - a[3]);
  ans += a[2]/2;
  a[2]%=2;
  ans += a[2];
  a[1] = max(0,a[1] - 2*a[2]);
  ans += (a[1]+3)/4;
  printf("%d\n",ans);
  return 0;
}