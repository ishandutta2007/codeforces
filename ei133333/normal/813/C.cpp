#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

int N, X;
vector< int > g[200000];
int depth[200000];

void dfs(vector< int > &far, int idx, int par = -1)
{
  if(~par) far[idx] = far[par] + 1;
  for(auto &to : g[idx]) {
    if(to == par) continue;
    dfs(far, to, idx);
    depth[idx] = max(depth[idx], depth[to] + 1);
  }
}

int main()
{
  cin >> N >> X;
  --X;
  for(int i = 1; i < N; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector< int > latte(N, 0), malta(N, 0);
  dfs(malta, X, -1);
  memset(depth, 0, sizeof(depth));
  dfs(latte, 0, -1);
  int ret = 0;
  for(int i = 0; i < N; i++) {
    if(latte[i] > malta[i]) ret = max(ret, latte[i]*2 + depth[i]*2);
  }
  cout << ret << endl;
}