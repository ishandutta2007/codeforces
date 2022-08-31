#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int N, D, K;
int nest = 0;
vector< pair< int, int > > g[400001];

void fail() {
  cout << "NO" << endl;
  exit(0);
}

void dfs(int idx, int l, int r, int par = -1, bool path = true) {
  if(l > 0 && r > 0) {
    while(nest < N && g[idx].size() < K) {
      g[idx].emplace_back(nest, false);
      g[nest].emplace_back(idx, false);
      ++nest;
    }
  }
  for(auto &e : g[idx]) {
    if(e.first == par) continue;
    if(e.second & path) {
      dfs(e.first, l + 1, r - 1, idx, true);
    } else {
      dfs(e.first, l - 1, r - 1, idx, false);
    }
  }
  if(g[idx].size() > K) fail();
}

int main() {
  cin >> N >> D >> K;
  for(int i = 1; i <= D; i++) {
    g[i].emplace_back(i - 1, true);
    g[i - 1].emplace_back(i, true);
  }
  nest = D + 1;
  dfs(0, 0, D);
  if(nest != N) fail();
  cout << "YES" << endl;
  for(int i = 0; i < N; i++) {
    for(auto &to : g[i]) {
      if(i < to.first) cout << i + 1 << " " << to.first + 1 << endl;
    }
  }
}