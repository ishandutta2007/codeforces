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
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 111
int N, X[MAXN], Y[MAXN];
bool done[MAXN];

void dfs(int x){
  done[x] = true;
  REP(i, N) if(!done[i] && (X[i] == X[x] || Y[i] == Y[x])) dfs(i);
}

int main(int argc, char *argv[]){
  int ans = -1;
  scanf("%d", &N);
  REP(i, N) scanf("%d%d", X + i, Y + i);
  REP(i, N) if(!done[i]){
    ans++;
    dfs(i);
  }
  printf("%d\n", ans);
  return 0;
}