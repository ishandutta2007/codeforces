#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int N, K, A[5][1000];
bool g[5][1000][1000];
vector< int > v[1000];
int dp[1000];

int rec(int idx) {
  if(~dp[idx]) return dp[idx];
  int ret = 1;
  for(auto to : v[idx]) ret = max(ret, rec(to) + 1);
  return dp[idx] = ret;
}
int main() {
  memset(dp, -1, sizeof(dp));
  cin >> N >> K;
  for(int i = 0; i < K; i++) {
    for(int j = 0; j < N; j++) {
      cin >> A[i][j];
      --A[i][j];
    }
    for(int j = 0; j < N; j++) {
      for(int k = j + 1; k < N; k++) {
        g[i][A[i][j]][A[i][k]] = true;
      }
    }
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      bool f = true;
      for(int k = 0; k < K; k++) {
        f &= g[k][i][j];
      }
      if(f) v[i].emplace_back(j);
    }
  }
  int ret = 0;
  for(int i = 0; i < N; i++) ret = max(ret, rec(i));
  cout << ret << endl;
}