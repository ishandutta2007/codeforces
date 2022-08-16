#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

const int64 INF = 1LL << 60;

vector< int64 > operator*(vector< int64 > &x, vector< int64 > &y)
{
  vector< int64 > z(x.size() + y.size() - 1, INF);
  for(int i = 0; i < x.size(); i++) {
    for(int j = 0; j < y.size(); j++) {
      z[i + j] = min(z[i + j], x[i] + y[j]);
    }
  }
  return (z);
}

int main()
{
  int N, W;
  cin >> N >> W;
  vector< int > a(N), b(N);
  vector< int > g[200000];
  for(int i = 0; i < N; i++) {
    int par;
    cin >> a[i] >> b[i];
    b[i] = a[i] - b[i];
    if(i > 0) {
      cin >> par;
      g[--par].emplace_back(i);
    }
  }
  vector< vector< int64 > > dp0(N), dp1(N), dp01(N);
  function< void(int) > dfs = [&](int idx)
  {
    dp0[idx] = {0, a[idx]};
    dp1[idx] = {INF, b[idx]};
    for(auto &to : g[idx]) {
      dfs(to);
      dp1[idx] = dp1[idx] * dp01[to];
      dp0[idx] = dp0[idx] * dp0[to];
    }
    dp01[idx].resize(dp0[idx].size());
    for(int i = 0; i < dp0[idx].size(); i++) {
      dp01[idx][i] = min(dp0[idx][i], dp1[idx][i]);
    }
  };

  dfs(0);
  int ret = 0;
  for(int i = 0; i < dp01[0].size(); i++) {
    if(dp01[0][i] <= W) ret = i;
  }

  cout << ret << endl;
}