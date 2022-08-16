#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

int main() {
  int N, M, A[4000], B[40000];
  vector< int > g[4000];

  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    cin >> A[i] >> B[i];
    --A[i], --B[i];
    g[A[i]].emplace_back(B[i]);
    g[B[i]].emplace_back(A[i]);
  }

  int ret = INF;
  for(int i = 0; i < M; i++) {
    // a[i] - c
    // b[i] - c
    vector< int > ex(N);
    for(int j : g[A[i]]) ++ex[j];
    for(int j : g[B[i]]) ++ex[j];
    for(int j = 0; j < N; j++) {
      if(ex[j] == 2) {
        ret = min< int >(ret, g[A[i]].size() + g[B[i]].size() + g[j].size());
      }
    }
  }
  if(ret == INF) cout << -1 << endl;
  else cout << ret-6 << endl;
}