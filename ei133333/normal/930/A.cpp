#include <bits/stdc++.h>

using namespace std;


int N;
vector< int > g[100000];
bool f[100001];

void dfs(int idx, int dep)
{
  f[dep] ^= 1;
  for(auto& to : g[idx]) dfs(to, dep + 1);
}

int main() {
  cin >> N;
  for(int i = 1; i < N; i++) {
    int x;
    cin >> x;
    --x;
    g[x].push_back(i);
  }
  dfs(0, 0);
  int ret = 0;
  for(int i = 0; i <= N; i++) {
    ret += f[i];
  }
  cout << ret << endl;
}