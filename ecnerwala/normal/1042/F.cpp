#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1.1e6;
int N, K;
vector<int> adj[MAXN];

int res = 0;
int dfs(int cur, int prv = 0) {
 int bestTop = K+1;
 int need = -1;
 if (adj[cur].size() == 1) need = 0;
 for (int nxt : adj[cur]) {
  if (nxt == prv) continue;
  int v = dfs(nxt, cur);
  if (v > K/2) bestTop = min(bestTop, v);
  else need = max(need, v);
 }
 if (need == -1 || need + bestTop <= K) return bestTop + 1;
 if (need == K/2) res++;
 return need + 1;
}

int main() {
 ios_base::sync_with_stdio(0), cin.tie(0);
 cin >> N >> K;
 for (int i = 0; i < N-1; i++) {
  int u,v; cin >> u >> v;
  adj[u].push_back(v);
  adj[v].push_back(u);
 }
 int st = 1;
 while (adj[st].size() == 1) st++;
 assert(st <= N);
 if (dfs(st) <= K/2) res++;
 cout << res << '\n';
}