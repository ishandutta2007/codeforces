#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

int N, K;
vector< int > g[200000];
int ans;

int dfs(int idx, int par, int dep) {
  bool need = false, ok = false;
  for(auto &to : g[idx]) {
    if(to == par) continue;
    auto beet = dfs(to, idx, dep + 1);
    if(beet == 0) need = true;
    else if(beet == 1) ok = true;
  }
  if(need) {
    if(idx > 0) {
      ++ans;
    }
    return 1;
  }
  if(ok || dep <= 2) { // 
    return 2;
  }
  return 0;
}

int main() {
  cin >> N;
  for(int i = 1; i < N; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  dfs(0, -1, 0);
  cout << ans << endl;
}