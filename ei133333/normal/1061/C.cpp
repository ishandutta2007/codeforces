#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int mod = 1e9 + 7;


int dp[1000001];

int main() {
  vector< int > div[1000001];
  for(int i = 100001; i > 1; i--) {
    for(int j = i; j <= 1000000; j += i) {
      div[j].emplace_back(i);
    }
  }

  int N, A[100000];
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for(int i = 0; i < N; i++) {
    for(auto &p : div[A[i]]) {
      dp[p] += dp[p - 1];
      if(dp[p] >= mod) dp[p] -= mod;
    }
    dp[1] += 1;
    if(dp[1] >= mod) dp[1] -= mod;
  }
  cout << accumulate(dp, dp + 1000001, 0LL) % mod << endl;
}