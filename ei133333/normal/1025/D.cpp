#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int N, A[700];
bitset< 700 > dp[700][700];
bool isok[700][700];
int checked[700][700];
int checked2[700][700];

int main() {
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];

  memset(checked, -1, sizeof(checked));
  memset(checked2, -1, sizeof(checked2));

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      isok[i][j] = __gcd(A[i], A[j]) > 1;
    }
  }

  auto update1 = [&](int left, int root) {
    if(~checked2[root][left]) return checked2[root][left];
    bool f = left == root;
    for(int ch = left; ch < root; ch++) {
      if(isok[ch][root] && dp[left][ch][root - 1]) {
        f = true;
        break;
      }
    }
    return checked2[root][left] = f;
  };

  auto update2 = [&](int root, int right) {
    if(~checked[root][right]) return checked[root][right];
    bool f = root == right;
    for(int ch = root + 1; ch <= right; ch++) {
      if(isok[ch][root] && dp[root + 1][ch][right]) {
        f = true;
        break;
      }
    }
    return checked[root][right] = f;
  };

  for(int range = 1; range <= N; range++) {
    for(int left = 0; left + range <= N; left++) {
      int right = left + range - 1;
      for(int root = left; root <= right; root++) {
        dp[left][root][right] = update1(left, root) && update2(root, right);
      }
    }
  }

  for(int i = 0; i < N; i++) {
    if(dp[0][i][N - 1]) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}