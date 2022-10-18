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

int g[111][111];
int N, M;
bool done[111];
vector<int> ans, tmp_ans;

int a[111];

bool dfs(int v, int res){
  if(a[v]) return a[v] == res;
  a[v] = res;
  done[v] = true;
  if(res == 1) tmp_ans.push_back(v);
  REP(i, N) if(g[v][i]) if(!dfs(i, res == g[v][i] * 2 - 3 ? 1 : -1)) return false;
  return true;
}

bool asphalt(int v){
  tmp_ans.clear();
  REP(i, N) a[i] = 0;
  if(dfs(v, 1)){
    REP(i, tmp_ans.size()) ans.push_back(tmp_ans[i]);
    return true;
  }
  tmp_ans.clear();
  REP(i, N) a[i] = 0;
  if(dfs(v, -1)){
    REP(i, tmp_ans.size()) ans.push_back(tmp_ans[i]);
    return true;
  }
  return false;
}

int main(int argc, char *argv[]){
  scanf("%d%d", &N, &M);
  int a, b, c;
  REP(i, M){
    scanf("%d%d%d", &a, &b, &c);
    g[a-1][b-1] = c + 1;
    g[b-1][a-1] = c + 1;
  }
  REP(i, N) if(!done[i]) if(!asphalt(i)){ printf("Impossible\n"); return 0; }
  printf("%d\n", (int)ans.size());
  REP(i, ans.size()){
    if(i) printf(" ");
    printf("%d", ans[i] + 1);
  }
  printf("\n");
  return 0;
}