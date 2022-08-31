#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N, M;
  set< pair< int, int > > graph[100000];
  bool uped[100000] = {};

  queue< int > que;

  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    graph[x].insert({y, i});
    graph[y].insert({x, i});
  }

  int ret = 0;
  for(int i = 0; i < N; i++) {
    if(graph[i].size() == 0) {
      ++ret;
      uped[i] = true;
    } else if(graph[i].size() == 1) {
      que.push(i);
    }
  }

  while(!que.empty()) {
    int v = que.front(); que.pop();
    if(graph[v].empty()) {
      if(uped[v]++) continue;
      ++ret;
    } else {
      auto p = *graph[v].begin();
      uped[v] = true;
      graph[v].erase(graph[v].begin());
      graph[p.first].erase({v, p.second});
      if(graph[p.first].size() <= 1) que.push(p.first);
    }
  }
  cout << ret << endl;
}