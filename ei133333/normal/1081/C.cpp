#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 998244353;

int N, M, K;
int dp[2001][2001];

int64 rec(int idx, int color) { // color==K
  if(color > K) return 0;
  if(N == idx) return color == K;
  if(~dp[idx][color]) return dp[idx][color];
  int64 ret = 0;
  ret += rec(idx + 1, color + 1) * (M - 1) % mod; // 
  ret += rec(idx + 1, color) % mod;
  ret %= mod;
  return dp[idx][color] = ret;
}

int main() {
  memset(dp, -1, sizeof(dp));
  cin >> N >> M >> K;
  cout << rec(1, 0) * M % mod << endl;
}