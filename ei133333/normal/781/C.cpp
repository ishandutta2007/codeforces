#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector< int > G[200000];

bool v[200000];
vector< int > tt;

void dfs(int idx, int par = -1)
{
  v[idx] = true;
  tt.push_back(idx);
  for(int to : G[idx]) if(!v[to]) dfs(to, idx);
  if(~par) tt.push_back(par);
}

int main()
{
  cin >> N >> M >> K;
  for(int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    --A, --B;
    G[A].push_back(B);
    G[B].push_back(A);
  }
  dfs(0);

  int sz = (2 * N + K - 1) / K, pos = 0;
  for(int i = 0; i < K; i++) {
    int get = min((int) tt.size() - pos, sz);
    if(get == 0) {
      cout << 1 << " " << 1 << endl;
    } else {
      cout << get;
      for(int j = 0; j < get; j++) cout << " " << tt[pos + j] + 1;
      cout << endl;
    }
    pos += get;
  }
}