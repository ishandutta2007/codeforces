#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, K;
  vector< int > g[100000];
  cin >> N >> K;
  int deg[100000] = {};
  bool used[100000] = {};
  queue< int > que;
  for(int i = 1; i < N; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
    deg[x]++;
    deg[y]++;
  }
  for(int i = 0; i < N; i++) {
    if(deg[i] == 1) {
      que.emplace(i);
      used[i] = true;
    }
  }
  int ret = 0;

  while(que.size()) {
    vector< int > add;
    set< int > acc;
    map< int, int > mp;
    while(que.size()) {
      int p = que.front();
      que.pop();
      for(auto &to : g[p]) {
        if(used[to]) continue;
        --deg[to];
        ++mp[to];
        if(deg[to] == 1) add.push_back(to);
        acc.emplace(to);
      }
    }
    
    if(acc.size() != add.size()) {
      cout << "No\n";
      return 0;
    }

    for(auto &p : add) {
      if(mp[p] <= 2) {
        cout << "No\n";
        return 0;
      }
      used[p] = true;
      que.emplace(p);
    }
    ++ret;

    if(que.size() == 1) {
      break;
    } else if(que.size() == 0) {
      cout << "No\n";
      return 0;
    }
  }

  if(ret == K) cout << "Yes\n";
  else cout << "No\n";
}