#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 100000 + 1;
constexpr int debug = 0;
int p[maxn], d[maxn], h[maxn], dn;
int ans[maxn];
char ss[maxn];
vector<int> fd[maxn], cd[maxn];
vector<int> G[maxn];
void DFS(int u){
  dn = max(dn, d[u]);
  fd[d[u]].push_back(u);
  h[u] = 1;
  for(int v : G[u]){
    d[v] = d[u] + 1;
    DFS(v);
    h[u] = max(h[u], h[v] + 1);
  }
}
int dp[500][maxn], v[500], vn;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, x;
  cin >> n >> x;
  for(int i = 2; i <= n; i += 1){
    cin >> p[i];
    G[p[i]].push_back(i);
  }
  DFS(d[1] = 1);
  map<int, int> mp;
  for(int i = 1; i <= dn; i += 1){
    int x = fd[i].size();
    if(not mp.count(x)){
      mp[x] = vn += 1;
      v[vn] = x;
    }
    cd[mp[x]].push_back(i);
  }
  for(int i = 0; i <= vn; i += 1)
    for(int j = 0; j <= n; j += 1) dp[i][j] = -1;
  dp[0][0] = 1;
  for(int i = 1; i <= vn; i += 1){
    for(int j = 0; j < v[i]; j += 1){
      queue<int> q;
      for(int k = j; k <= n; k += v[i]){
        if(dp[i - 1][k] != -1) q.push(k);
        while(not q.empty() and q.front() < k - v[i] * (int)cd[i].size()) q.pop();
        if(not q.empty()) dp[i][k] = q.front();
      }
    }
    if(debug){
      cout << v[i] << ":";
      for(int j = 0; j <= n; j += 1) cout << dp[i][j] << " ";
      cout << "\n";
    }
  }
  int y = x;
  while(dp[vn][y] == -1) y -= 1;
  int xx = dn;
  for(int i = vn, j = y; i; i -= 1){
    for(int k = 0; k < (j - dp[i][j]) / v[i]; k += 1){
      ans[cd[i][k]] = 1;
    }
    j = dp[i][j];
  }
  for(int i = 1; i <= n; i += 1) ss[i] = char('b' - ans[d[i]]);
  if(x - y > 0) for(int i = dn; i >= 1; i -= 1) if(ans[i] == 0 and fd[i].size() >= x - y){
    sort(fd[i].begin(), fd[i].end(), [&](const int& x, const int& y){
      return h[x] < h[y];
    });
    for(int j = 0; j < x - y; j += 1) ss[fd[i][j]] = 'a'; 
    xx += h[fd[i][x - y - 1]];
    x = y;
    break;
  }
  assert(x == y);
  cout << xx << "\n" << (ss + 1);
  return 0;
}