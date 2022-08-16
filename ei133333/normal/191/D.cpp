#include <bits/stdc++.h>

using namespace std;

using int64 = long long;


int N, M;
vector< int > g[100000];
bool v[100000];
set< int > st;

void dfs(int idx)
{
  if(g[idx].size() != 2) {
    st.emplace(idx);
    return;
  }
  v[idx] = true;
  for(auto &to : g[idx]) {
    if(!v[to]) dfs(to);
  }
}

int main()
{
  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }

  int ret = 0;
  for(int i = 0; i < N; i++) {
    ret += g[i].size() % 2;
  }
  ret /= 2;
  for(int i = 0; i < N; i++) {
    if(g[i].size() == 2 && !v[i]) {
      st.clear();
      dfs(i);
      if(st.size() <= 1) ++ret;
    }
  }
  cout << ret << " " << M << endl;
}