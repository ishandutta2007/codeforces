#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 29;

int N, A[5001];
int dp[5001][5001][2];

int rec(int l, int r, int t) {
  if(l == 0 && r + 1 == N) return 0;
  if(~dp[l][r][t]) return dp[l][r][t];
  int ret = INF, c = t ? A[r] : A[l];
  if(l > 0) {
    if(A[l - 1] == c) ret = min(ret, rec(l - 1, r, false));
    else ret = min(ret, rec(l - 1, r, false) + 1);
  }
  if(r + 1 < N) {
    if(A[r + 1] == c) ret = min(ret, rec(l, r + 1, true));
    else ret = min(ret, rec(l, r + 1, true) + 1);
  }
  return dp[l][r][t] = ret;
}

int main() {
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  int ret = INF;
  memset(dp, -1, sizeof(dp));
  for(int i = 0; i < N; i++) ret = min(ret, rec(i, i, 0));
  cout << ret << endl;
}