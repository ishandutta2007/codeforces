#include <bits/stdc++.h>

using namespace std;

const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;

int dp1[101][10001];
int dp2[101][10001];

vector< vector< int64_t > > get_combination(int N, int mod) {
  vector< vector< int64_t > > mat(N + 1, vector< int64_t >(N + 1));
  for(int i = 0; i <= N; i++) {
    for(int j = 0; j <= i; j++) {
      if(j == 0 || j == i) mat[i][j] = 1;
      else mat[i][j] = mat[i - 1][j - 1] + mat[i - 1][j];
      mat[i][j] %= mod;
    }
  }
  return (mat);
}

auto comb1 = get_combination(100, mod1);
auto comb2 = get_combination(100, mod2);


int main() {
  int N, A[100];
  cin >> N;
  map< int, int > cnt;
  dp1[0][0] = 1;
  dp2[0][0] = 1;
  int all = 0;
  for(int i = 0; i < N;i++) {
    cin >> A[i];
    cnt[A[i]]++;
    all += A[i];
    for(int j = i + 1; j > 0; j--) {
      for(int k = 10000; k >= A[i]; k--) {
        (dp1[j][k] += dp1[j - 1][k - A[i]]);
        (dp2[j][k] += dp2[j - 1][k - A[i]]);
        if(dp1[j][k] >= mod1) dp1[j][k] -= mod1;
        if(dp2[j][k] >= mod2) dp2[j][k] -= mod2;
      }
    }
  }
  if(cnt.size() <= 2) {
    cout << N << endl;
    return 0;
  }
  int ret = 1;
  for(auto &p : cnt) {
    for(int j = 2; j <= p.second; j++) {
      int weight_sum = p.first * j;
      if(dp1[j][weight_sum] == comb1[p.second][j] && dp2[j][weight_sum] == comb2[p.second][j]) {
        ret = max(ret, j);
      }

    }
  }
  cout << ret << endl;
}