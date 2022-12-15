#include <bits/stdc++.h>
using namespace std;

const int ms = 1e5+5;

int vis[ms];
vector<int> g[ms];
int edgesTo[ms];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  while(m--) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  for(int i = 1; i <= n; i++) {
    q.push({0, i});
  }
  int ans = 0;
  int cnt = 0;
  while(q.size() > 0) {
    int u = q.top().second;
    int x = q.top().first;
    q.pop();
    if(x != edgesTo[u]) continue;
    if(cnt == x) ans++;
    cnt++;
    vis[u] = 1;
    for(int v : g[u]) {
      if(!vis[v]) {
        edgesTo[v]++;
        q.push({edgesTo[v], v});
      }
    }
  }
  cout << ans-1 << '\n';
}