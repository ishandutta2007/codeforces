#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int mod = 1e9 + 7;

int main() {
  int N, A, B, K;
  cin >> N >> A >> B >> K;
  --A, --B;

  vector< pair< int, int > > comp[5000];

  for(int x = 0; x < N; x++) {
    bool ok[5000] = {};
    for(int y = 0; y < N; y++) {
      if(x == y) continue;
      if(abs(x - y) < abs(x - B)) {
        ok[y] = true;
      }
    }
    for(int i = 0; i < N; i++) {
      if(!ok[i]) continue;
      if(comp[x].empty() || comp[x].back().second + 1 != i) {
        comp[x].emplace_back(i, i);
      } else {
        comp[x].back().second++;
      }
    }
  }

  vector< int > dp(N + 1);
  dp[A] = 1;
  for(int k = 0; k < K; k++) {
    vector< int > dp2(N + 1);
    for(int i = 0; i < N; i++) {
      for(auto &p : comp[i]) {
        (dp2[p.first] += dp[i]) %= mod;
        (dp2[p.second + 1] += mod - dp[i]) %= mod;
      }
    }
    for(int i = 1; i <= N; i++) {
      (dp2[i] += dp2[i - 1]) %= mod;
    }
    dp.swap(dp2);
  }
  dp.pop_back();
  cout << accumulate(begin(dp), end(dp), 0LL) % mod << endl;
}