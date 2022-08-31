#include <bits/stdc++.h>

using namespace std;

int N, M;
vector< int > g[100000];
int v[100000];


int dfs2(int idx, int depth = 0, int par = -1)
{
  v[idx] = depth;
  vector< int > child;
  for(auto &to : g[idx]) {
    if(to == par) continue;
    if(~v[to]) {
      if(depth < v[to]) child.push_back(to);
      continue;
    }
    int get = dfs2(to, depth + 1, idx);
    if(~get) cout << idx + 1 << " " << to + 1 << " " << get + 1 << endl;
    else child.push_back(to);
  }

  while(child.size() >= 2) {
    cout << child[child.size() - 2] + 1 << " " << idx + 1 << " " << child[child.size() - 1] + 1 << endl;
    child.pop_back();
    child.pop_back();
  }
  if(child.size()) return (child.back());
  return (-1);
}

int main()
{
  scanf("%d %d", &N, &M);
  for(int i = 0; i < M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }

  if(M % 2 == 1) {
    puts("No solution");
    return (0);
  }

  memset(v, -1, sizeof(v));
  for(int i = 0; i < N; i++) {
    if(~v[i]) continue;
    dfs2(i, 0);
  }
}