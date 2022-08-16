#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int64 M, K, P;
vector< int > g[100000];
vector< int > dep;


void dfs(int idx, int depth, int par = -1)
{
  dep.push_back(depth);
  for(auto &to : g[idx]) {
    if(to == par) continue;
    dfs(to, depth + 1, idx);
  }
}

int main()
{
  cin >> M >> K >> P;
  for(int i = 0; i < M - 1; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0, 0);
  sort(begin(dep), end(dep));
  int64 ret = 1;
  int64 head = 1, latte = 0, malta = 0;
  for(int i = 1; i < dep.size(); i++) {
    if(dep[i] != dep[i - 1]) latte += malta;
    while(latte > P && head < dep.size()) {
      --malta;
      latte -= dep[i] - dep[head];
      ++head;
    }
    if(latte <= P) {
      ret = max(ret, 1 + malta);
    }
    malta++;
  }

  cout << min(K, ret) << endl;
}