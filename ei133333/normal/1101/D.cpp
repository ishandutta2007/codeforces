#include<bits/stdc++.h>

using namespace std;

using int64 = long long;


int N;
vector< int > g[200000];
vector< int > v[200001];
bool ok[200000];
bool used[200000];

map< int64_t, int > prime_factor(int64_t n) {
  map< int64_t, int > ret;
  for(int64_t i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return (ret);
}

pair< int, int > dfs(int idx, int par) {
  used[idx] = true;
  pair< int, int > ret(0, idx);
  for(auto &to : g[idx]) {
    if(to == par) continue;
    if(!ok[to]) continue;
    auto cost = dfs(to, idx);
    cost.first += 1;
    ret = max(ret, cost);
  }
  return ret;
}

int main() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    int x;
    cin >> x;
    auto st = prime_factor(x);
    for(auto &p : st) v[p.first].emplace_back(i);
  }
  for(int i = 1; i < N; i++) {
    int s, t;
    cin >> s >> t;
    --s, --t;
    g[s].emplace_back(t);
    g[t].emplace_back(s);
  }
  int ret = 0;
  for(int i = 2; i < 200000; i++) {
    for(auto &x : v[i]) {
      ok[x] = true;
      used[x] = false;
    }
    for(auto &x : v[i]) {
      if(used[x]) continue;
      auto p = dfs(x, -1);
      auto q = dfs(p.second, -1);
      ret = max(ret, q.first+1);
    }
    for(auto &x : v[i]) {
      ok[x] = false;
    }
  }
  cout << ret << endl;
}