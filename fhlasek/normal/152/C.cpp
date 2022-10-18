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

char a[111][111];

#define MOD 1000000007

set<char> s;

int main(int argc, char *argv[]){
  int N,M;
  scanf("%d%d",&N,&M);
  REP(i,N) scanf("%s",a[i]);
  int ans = 1;
  REP(j,M){
    s.clear();
    REP(i,N) s.insert(a[i][j]);
    ans = ((long long) ans * s.size()) % MOD;
  }
  printf("%d\n",ans); 
  return 0;
}