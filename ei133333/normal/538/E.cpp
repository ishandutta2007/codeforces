#include<bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

int dfs2(int);

int N, all;
vector< int > g[200000];

int dfs(int idx)
{
  if(g[idx].empty()) {
    ++all;
    return (1);
  }
  int ret = INF;
  for(auto &to : g[idx]) ret = min(ret, dfs2(to));
  return (ret);
}

int dfs2(int idx)
{
  if(g[idx].empty()) return (1);
  int ret = 0;
  for(auto &to : g[idx]) ret += dfs(to);
  return (ret);
}

int main()
{
  cin >> N;
  for(int i = 1; i < N; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
  }
  int get = dfs(0);
  cout << all + 1 - get << " " << dfs2(0) << endl;
}