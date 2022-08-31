#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int64 M, T;
/*
  int A[111][111];
  for(int M = 1; M <= 14; M++) {
    for(int j = 1; j <= M; j++) {
      A[1][j] = 0;
    }
    A[1][M + 1] = 1;

    for(int i = 2; i <= M + 1; i++) {
      for(int j = 1; j <= M + 1; j++) {
        if(j == 1) {
          A[i][j] = A[i - 1][j + 1];
        } else if(j == M + 1) {
          A[i][j] = A[i - 1][j - 1];
        } else {
          A[i][j] = A[i - 1][j - 1] ^ A[i - 1][j + 1];
        }
      }
    }

    for(int i = 1; i <= M + 1; i++) {
      int ret = 0;
      for(int j = 1; j <= M + 1; j++) {
        cout << A[i][j] << " ";
        ret += A[i][j];
      }

      cout << "[" << ret << "]" << endl;
    }
  }

  */


  cin >> M >> T;

  int64 vv = 1, log = 1;
  for(; vv < T; vv <<= 1LL, ++log);

  if(vv != T) {
    cout << 0 << endl;
    return (0);
  }

  int64 dp[61][61], calc = 0, ret = 0LL;
  for(int i = 0; i <= 60; i++) {
    dp[i][0] = 1;
    for(int j = 1; j <= i; j++) {
      dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
    }
  }
  for(int i = 60; i >= 0; i--) {
    if(log < 0) break;
    if(calc + (1LL << i) <= M + 1) {
      ret += dp[i][log--];
      calc += (1LL << i);
    }
  }

  cout << ret + (log == 0) - (T == 1) << endl;
}