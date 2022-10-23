#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn=1e5+10;
char s[maxn];
int n,m;
vector<int> G[maxn];
bool vis[maxn];
int dp[maxn];
 
int bfs(){
  memset(dp, INF, sizeof dp);
  dp[1] = 0;
  vis[1] = true;
  queue<int> q;
  q.push(1);
 
  while(!q.empty()){
    int u = q.front();  q.pop();
    if(u == n)  return dp[u];
    for(int i = 0; i < G[u].size(); ++i){
      int v = G[u][i];
      if(dp[v] > dp[u] + 1){
        dp[v] = dp[u] + 1;
        if(vis[v])  continue;
        vis[v] = true;
        q.push(v);
      }
    }
  }
  return -1;
}
 
int main(){
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; ++i){
    scanf("%s", s+1);
    for(int j = 1; j <= m; ++j)
      if(s[j] == '#'){
        G[i].push_back(j+n);
        G[j+n].push_back(i);
      }
  }
  printf("%d\n", bfs());
  return 0;
}