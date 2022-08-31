#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;


int N, A[1000];

int dp[1001][1001][2];

int rec(int idx, int size, bool catched) {
  if(idx == N) return 0;
  if(~dp[idx][size][catched]) return dp[idx][size][catched];
  int ret = 0;
  if(!catched) {
    if(1 <= A[idx] && A[idx] <= 1000) {
      ret += rec(idx + 1, A[idx], true);
    }
    ret += rec(idx + 1, 0, false);
    ret %= mod;
  } else {
    if(size == 1) {
      ++ret;
      ret += rec(idx + 1, 0, false);
    } else {
      ret += rec(idx + 1, size - 1, true);
    }
    ret += rec(idx + 1, size, true);
    ret %= mod;
  }
  return dp[idx][size][catched] = ret;
}

int main() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  memset(dp, -1, sizeof(dp));
  cout << rec(0, 0, false) << endl;
}