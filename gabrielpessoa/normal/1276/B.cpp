#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;

const int ms = 3e5+5;
const int inf = 1e18;

int comp[ms];
int cur = 0;
vector<int> g[ms];
int sz[ms];
int n, m, a, b;
int markA[ms], markB[ms];

void dfs(int u) {
  stack<int> s;
  s.push(u);
  while(!s.empty()) {
    int u = s.top();
    s.pop();
    if(comp[u] || u == a || u == b) continue;
    comp[u] = cur;
    sz[cur]++;
    // cout << u << " comp " << comp[u] << " sz " << sz[cur] << endl;
    for(int v : g[u]) s.push(v); 
  }
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--) {
    cin >> n >> m >> a >> b;
    for(int i = 1; i <= n; i++) {
      comp[i] = 0;
      markA[i] = 0;
      markB[i] = 0;
      sz[i] = 0;
      g[i].clear();
      cur = 0;
    }
    for(int i = 0; i < m; i++) {
      int u, v; 
      cin >> u >> v;
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    for(int i = 1; i <= n; i++) {
      if(!comp[i]) {
        ++cur;
        dfs(i);
      }
    }
    for(int v : g[a]) markA[comp[v]] = 1;
    for(int v : g[b]) markB[comp[v]] = 1;
    int ansA = 0, ansB = 0;
    for(int i = 1; i <= cur; i++) {
      if(markA[i] && !markB[i]) ansA += sz[i];
      if(markB[i] && !markA[i]) ansB += sz[i];
    }
    cout << ansA * ansB << '\n';
  }
}