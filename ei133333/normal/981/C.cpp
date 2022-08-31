#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

// 

int N;
vector< int > g[100000];
vector< int > leaf;

bool dfs(int idx, int par) {
  int child = 0;
  for(auto &to : g[idx]) {
    if(to == par) continue;
    if(!dfs(to, idx)) return false;
    ++child;
  }
  if(child == 0) leaf.emplace_back(idx);
  if(child >= 2) return false;
  return true;
}

int main() {
  cin >> N;
  for(int i = 1; i < N; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }

  int ret = 0;
  for(int i = 0; i < N; i++) {
    ret = max(ret, (int) g[i].size());
  }

  for(int i = 0; i < N; i++) {
    if(ret == g[i].size()) {
      for(auto &to : g[i]) {
        if(!dfs(to, i)) {
          cout << "No" << endl;
          return 0;
        }
      }
      cout << "Yes" << endl;
      cout << leaf.size() << endl;
      for(auto& e : leaf) cout << i + 1 << " " << e + 1 << endl;
      return 0;
    }
  }

}