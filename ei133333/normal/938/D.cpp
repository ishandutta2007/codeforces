#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

struct edge
{
  int to;
  int64 cost;
};

int N, M;
vector< edge > g[200000];
int64 D[200000];
int64 ms[200000];

int main()
{
  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int x, y;
    int64 z;
    cin >> x >> y >> z;
    --x, --y;
    g[x].emplace_back((edge) {y, z * 2});
    g[y].emplace_back((edge) {x, z * 2});
  }
  for(int i = 0; i < N; i++) {
    cin >> D[i];
  }

  using Pi = pair< int64, int >;
  priority_queue< Pi, vector< Pi >, greater< Pi > > que;
  for(int i = 0; i < N; i++) {
    que.emplace(D[i], i);
    ms[i] = D[i];
  }
  while(que.size()) {
    int64 cost;
    int idx;
    tie(cost, idx) = que.top();
    que.pop();
    if(ms[idx] < cost) continue;
    for(auto &e : g[idx]) {
      if(ms[e.to] <= cost + e.cost) continue;
      ms[e.to] = cost + e.cost;
      que.emplace(ms[e.to], e.to);
    }
  }

  for(int i = 0; i < N; i++) {
    cout << ms[i] << " ";
  }
}