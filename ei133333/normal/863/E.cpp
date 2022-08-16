#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

struct edge
{
  int to, cost, idx;
};

typedef vector< vector< edge > > Graph;

int N, L[200000], R[200000];
int min_cost[400001];
int pv[400001], dd[400001];
bool used[400001];

bool Dijkstra(Graph &g, int s)
{
  typedef pair< int, int > Pi;
  int reach = s;
  priority_queue< Pi, vector< Pi >, greater< Pi > > que;
  que.emplace(0, s);
  min_cost[s] = 0;
  pv[s] = -1;
  while(!que.empty()) {
    auto p = que.top();
    que.pop();
    if(p.first > min_cost[p.second]) continue;
    for(auto &e : g[p.second]) {
      if(p.first + e.cost >= min_cost[e.to]) continue;
      reach = max(reach, e.to);
      min_cost[e.to] = p.first + e.cost;
      pv[e.to] = p.second;
      dd[e.to] = e.idx;
      que.emplace(min_cost[e.to], e.to);
    }
  }
  int now = reach;
  while(now != s) {
    used[dd[now]] = true;
    now = pv[now];
  }
  return (-1);
}

int main()
{
  scanf("%d", &N);
  vector< int > vs;
  for(int i = 0; i < N; i++) {
    scanf("%d %d", &L[i], &R[i]);
    ++R[i];
    vs.emplace_back(L[i]);
    vs.emplace_back(R[i]);
  }
  sort(begin(vs), end(vs));
  vs.erase(unique(begin(vs), end(vs)), end(vs));
  Graph g(vs.size());
  for(int i = 0; i < N; i++) {
    L[i] = lower_bound(begin(vs), end(vs), L[i]) - begin(vs);
    R[i] = lower_bound(begin(vs), end(vs), R[i]) - begin(vs);
    g[L[i]].emplace_back((edge) {R[i], 1, i});
  }
  for(int i = (int) vs.size() - 1; i >= 0; i--) {
    g[i].emplace_back((edge) {i - 1, 0, 400000});
  }

  fill_n(min_cost, 400001, INF);
  for(int i = 0; i < vs.size(); i++) {
    if(min_cost[i] == INF) Dijkstra(g, i);
  }
  for(int i = 0; i < N; i++) {
    if(!used[i]) {
      cout << i + 1 << endl;
      return(0);
    }
  }

  cout << -1 << endl;
}