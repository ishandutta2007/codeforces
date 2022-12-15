#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int ms = 4e5+5;

int reachCircle[ms];
int w[ms];
vii g[ms];
int u[ms], v[ms];
int vis[ms], visiting[ms];
int canCycle[ms];
int hasAns[ms];
int ans[ms];

int dfsCycle(int x) {
  if(vis[x]) return canCycle[x];
  else if(visiting[x]) return 1;
  else {
    visiting[x] = 1;
    canCycle[x] = 0;
    for(auto e : g[v[x]]) {
      if(e.first != u[x]) {
        canCycle[x] |= dfsCycle(e.second);
      }
    }
    vis[x] = 1;
    return canCycle[x];
  }
}

int poss[ms];

int solve(int x) {
  if(hasAns[x]) return ans[x];
  hasAns[x] = 1;
  ans[x] = 0;
  for(auto e : g[v[x]]) {
    if(e.first != u[x]) {
      ans[x] = max(ans[x], solve(e.second));
    }
  }
  ans[x] += w[v[x]];
  return ans[x];
}

main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  for(int i = 0; i < m; i++) {
    cin >> u[i*2] >> v[i*2];
    u[i*2+1] = v[i*2];
    v[i*2+1] = u[i*2];
    g[u[i*2]].emplace_back(v[i*2], i*2);
    g[v[i*2]].emplace_back(u[i*2], i*2+1);
  }
  int s;
  cin >> s;
  for(int i = 0; i < m+m; i++) {
    dfsCycle(i);
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    poss[i] = 0;
    for(auto e : g[i]) {
      if(canCycle[e.second]) { 
        poss[i]++;
      }
    }
    if(poss[i] > 1) {
      ans += w[i];
    }
  }
  if(poss[s] == 0) {
    for(auto e : g[s]) {
      ans = max(ans, solve(e.second));
    }
    ans += w[s];
    cout << ans << endl;
    return 0;
  }
  if(poss[s] == 1) {
    while(poss[s] == 1) {
      ans += w[s];
      w[s] = 0;
      for(auto e : g[s]) {
        if(canCycle[e.second]) {
          s = e.first;
        }
      }
    }
  }
  int best = 0;
  for(int i = 0; i < m+m; i++) {
    if(!canCycle[i]) {
      best = max(best, solve(i));
    }
  }
  cout << ans + best << endl;
}