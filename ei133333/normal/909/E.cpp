#include <bits/stdc++.h>

using namespace std;


int main()
{
  int N, M, E[100000];
  int in[100000] = {};
  vector< int > g[100000];

  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    cin >> E[i];
  }
  for(int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    g[x].emplace_back(y);
    in[y]++;
  }
  queue< int > que[2];
  for(int i = 0; i < N; i++) {
    if(in[i] == 0) que[E[i]].emplace(i);
  }
  int ret = 0;
  while(que[0].size() || que[1].size()) {
    bool which = que[0].empty();
    ret += which;
    while(!que[which].empty()) {
      int p = que[which].front();
      que[which].pop();
      for(auto& to : g[p]) {
        if(--in[to] == 0) {
          que[E[to]].emplace(to);
        }
      }
    }
  }

  cout << ret << endl;
}