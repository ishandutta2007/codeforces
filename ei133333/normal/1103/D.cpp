#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 60;


map< int64_t, int > prime_factor(int64_t n) {
  map< int64_t, int > ret;
  for(int64_t i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return (ret);
}

int main() {
  int N;
  int64 A[1000000], B[1000000], K;

  scanf("%d %lld", &N, &K);
  for(int i = 0; i < N; i++) scanf("%lld", &A[i]);
  for(int i = 0; i < N; i++) scanf("%lld", &B[i]);

  int64 gcd = 0;
  for(int i = 0; i < N; i++) gcd = __gcd(A[i], gcd);
  auto factors = prime_factor(gcd);

  vector< int64 > factor;
  for(auto &p : factors) factor.emplace_back(p.first);
  int M = (int) factor.size();

  map< vector< int64 >, vector< int64 > > mp;
  vector< int64 > v(M);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      v[j] = 1;
      while(A[i] % factor[j] == 0) {
        A[i] /= factor[j];
        v[j] *= factor[j];
      }
    }
    mp[v].emplace_back(B[i]);
  }

  vector< vector< int64 > > dp2(1 << M, vector< int64 >(M + 1, INF));
  dp2[0][0] = 0;

  for(auto &obj : mp) {
    auto &mul = obj.first;
    auto &vs = obj.second;
    sort(begin(vs), end(vs));
    for(int i = 1; i < vs.size(); i++) {
      vs[i] += vs[i - 1];
    }
    vector< int64 > dp(1 << M, INF);
    for(int i = 0; i < (1 << M); i++) {
      int64 mul2 = 1;
      for(int j = 0; j < M; j++) {
        if((i >> j) & 1) mul2 *= mul[j];
      }
      if(mul2 <= K) dp[i] = 1;
    }
    for(int i = 0; i < (1 << M); i++) {
      for(int j = i; j > 0; j = (j - 1) & i) {
        if(j == i) continue;
        dp[i] = min(dp[i], dp[j] + dp[i ^ j]);
      }
    }
    for(int i = (1 << M) - 1; i >= 0; i--) {
      for(int j = i; j > 0; j = (j - 1) & i) {
        if(dp[j] > vs.size()) continue;
        for(int64 k = 0; k + dp[j] <= M; k++) {
          dp2[i][k + dp[j]] = min(dp2[i][k + dp[j]], dp2[i ^ j][k] + vs[dp[j] - 1]);
        }
      }
    }
  }
  int64 ret = INF;
  for(int i = 0; i <= M; i++) {
    auto res = dp2[(1 << M) - 1][i];
    if(res >= INF) continue;
    ret = min(ret, res * i);
  }
  if(ret >= INF) ret = -1;
  cout << ret << endl;
}