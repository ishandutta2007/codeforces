#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 60;

int N, P[100000];
vector< int > g[100000];

int64 dfs(int idx, int64 add) {
  int64 ret = 0;
  if(P[idx] >= 0) {
    if(P[idx] < add) {
      cout << -1 << endl;
      exit(0);
    }
    ret += P[idx] - add;
    add += P[idx] - add;
    for(auto &to : g[idx]) ret += dfs(to, add);
  } else {
    int64 mergin = INF;
    for(auto &to : g[idx]) {
      mergin = min(mergin, P[to] - add);
    }
    if(mergin < 0) {
      cout << -1 << endl;
      exit(0);
    }
    if(mergin != INF) {
      ret += mergin;
      add += mergin;
      for(auto& to : g[idx]) ret += dfs(to, add);
    }
  }
  return ret;
}

int main() {
  cin >> N;
  for(int i = 1; i < N; i++) {
    int p;
    cin >> p;
    g[--p].emplace_back(i);
  }
  for(int i = 0; i < N; i++) {
    cin >> P[i];
  }
  cout << dfs(0, 0) << endl;
}