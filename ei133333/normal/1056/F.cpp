#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

void beet() {
  int N, A[100], P[100];
  double C, T;
  cin >> N;
  cin >> C >> T;
  vector< pair< int, int > > dat(N);
  for(auto &p : dat) cin >> p.first >> p.second;
  sort(dat.rbegin(), dat.rend());
  for(int i = 0; i < N; i++) tie(A[i], P[i]) = dat[i];
  double mat[100][101];
  for(int i = 0; i < N; i++) {
    mat[i][0] = A[i] / 0.9;
    for(int j = 1; j <= 100; j++) {
      mat[i][j] = mat[i][j - 1] / 0.9;
    }
  }

  vector< vector< double > > dp(1001, vector< double >(101, 1e50));
  dp[0][0] = 0;
  for(int i = 0; i < N; i++) {
    for(int k = 1000; k >= P[i]; k--) {
      for(int j = i; j >= 0; j--) {
        dp[k][j + 1] = min(dp[k][j + 1], dp[k - P[i]][j] + mat[i][j]); // j
      }
    }
  }

  int ret = 0;
  for(int i = 0; i < 1001; i++) {
    for(int k = 0; k < 101; k++) {
      if(dp[i][k] >= 1e50) continue;

      double left = 0, right = T;

      auto f = [&](double t) {
        return t + dp[i][k] / (1 + C * t);
      };

      for(int j = 0; j < 100; j++) {
        double latte = (left * 2 + right) / 3;
        double malta = (left + right * 2) / 3;
        if(f(latte) < f(malta)) right = malta;
        else left = latte;
      }
      if(f(left)+10*k + (1e-9) <= T) {
        ret = max(ret, i);
      }
    }
  }

  cout << ret << endl;

}

int main() {
  int TC;
  cin >> TC;
  while(TC--) beet();
}