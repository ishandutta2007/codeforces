#include<bits/stdc++.h>

using namespace std;

int N;
vector< int > g[100000];

int dfs(int idx, bool dep, int par)
{
  int ret = 0;
  for(auto &to : g[idx]) {
    if(to != par) {
      ret += dfs(to, !dep, idx) + dep;
    }
  }
  return (ret);
}

int main()
{
  cin >> N;
  for(int i = 1; i < N; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  int x = dfs(0, true, -1);
  int y = N - x;
  cout << 1LL * x * y - (N - 1) << endl;
}