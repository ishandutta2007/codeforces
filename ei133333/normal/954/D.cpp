#include<bits/stdc++.h>

using namespace std;

const int INF = 1 << 29;

int N, M, S, T;
int X[1000], Y[1000];
vector< int > g[1000];
bool ex[1000][1000];

vector< int > bfs(int s) {
  queue< int > q;
  q.emplace(s);
  vector< int > ms(N, INF);
  ms[s] = 0;
  while(q.size()) {
    int p = q.front();
    q.pop();
    for(auto &to : g[p]) {
      if(ms[to] == INF) {
        ms[to] = ms[p] + 1;
        q.emplace(to);
      }
    }
  }
  return ms;
}

int main() {
  cin >> N >> M >> S >> T;
  --S, --T;
  for(int i = 0; i < M; i++) {
    cin >> X[i] >> Y[i];
    --X[i], --Y[i];
    g[X[i]].emplace_back(Y[i]);
    g[Y[i]].emplace_back(X[i]);
    ex[X[i]][Y[i]] = ex[Y[i]][X[i]] = true;
  }
  auto latte = bfs(S);
  auto malta = bfs(T);
  int ret = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < i; j++) {
      if(ex[i][j]) continue;
      if(min(latte[i] + malta[j], latte[j] + malta[i]) + 1 >= latte[T]) {
        ++ret;
      }
    }
  }
  cout << ret << endl;
}