#include <bits/stdc++.h>

using namespace std;

constexpr char tap = 26;
const int INF = 1 << 28;

int N;
string S;
int dp[500][501][27];
bool ok[27][500][501];

void chmin(int &a, int b) {
  a = min(a, b);
}

int main() {
  cin >> N;
  cin >> S;
  for(auto &c : S) c -= 'a';
  fill_n(**dp, 500 * 501 * 27, INF);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < 27; j++) {
      chmin(dp[i][i + 1][j], S[i] == j ? 0 : 1);
    }
  }
  for(int i = 0; i < 26; i++) {
    for(int j = 0; j < N; j++) {
      for(int k = j; k < N; k++) {
        if(S[k] != i) break;
        chmin(dp[j][k + 1][i], 0);
      }
    }
  }

  for(int len = 1; len <= N; len++) {
    for(int left = 0; left <= N - len; left++) {
      int right = left + len;
      for(int value = 0; value < 26; value++) {
        for(int mid = left + 1; mid < right; mid++) {
          chmin(dp[left][right][value], dp[left][mid][tap] + dp[mid][right][value]);
          chmin(dp[left][right][value], dp[left][mid][value] + dp[mid][right][tap]);
          chmin(dp[left][right][value], dp[left][mid][value] + dp[mid][right][value]);
        }
      }
      for(int mid = left + 1; mid < right; mid++) {
        chmin(dp[left][right][tap], dp[left][mid][tap] + dp[mid][right][tap]);
      }
      for(int i = 0; i < 26; i++) {
        chmin(dp[left][right][tap], dp[left][right][i] + 1);
      }
    }
  }
  cout << dp[0][N][tap] << endl;
}