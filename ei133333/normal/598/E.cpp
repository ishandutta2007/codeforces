#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 60;

int T;
int64 dp[31][31][51];

int64 rec(int y, int x, int k) {
  if(k == 0 || y * x == k) return 0LL;
  if(~dp[y][x][k]) return dp[y][x][k];
  int64 ret = INF;
  for(int t = 1; t < y; t++) {
    for(int p = 0; p <= k; p++) {
      ret = min(ret, rec(t, x, p) + rec(y - t, x, k - p) + x * x);
    }
  }
  for(int t = 1; t < x; t++) {
    for(int p = 0; p <= k; p++) {
      ret = min(ret, rec(y, t, p) + rec(y, x - t, k - p) + y * y);
    }
  }
  return dp[y][x][k] = ret;
}

int main() {
  cin >> T;
  memset(dp, -1, sizeof(dp));
  while(T--) {
    int N, M, K;
    cin >> N >> M >> K;
    cout << rec(N, M, K) << endl;
  }
}