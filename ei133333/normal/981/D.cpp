#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

// 

int main() {
  int N, K;
  int64 A[50];
  cin >> N >> K;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  bool lock[61] = {};
  for(int i = 60; i >= 0; i--) {
    vector< bool > dp(N + 1);
    dp[0] = true;
    lock[i] = true;
    for(int j = 0; j < K; j++) {
      vector< bool > dp2(N + 1);
      for(int k = 0; k < N; k++) {
        if(!dp[k]) continue;
        int64 sum = 0;
        for(int l = k; l < N; l++) {
          sum += A[l];

          bool ok = true;
          for(int64 m = 0; m <= 60; m++) {
            if(lock[m]) {
              if((sum >> m) & 1) {
              } else {
                ok = false;
                break;
              }
            }
          }
          if(ok) dp2[l + 1] = true;
        }
      }
      dp.swap(dp2);
    }
    if(!dp[N]) lock[i] = false;
  }

  int64 ret = 0;
  for(int64 i = 0; i < 61; i++) {
    if(lock[i]) ret |= 1LL << i;
  }
  cout << ret << endl;
}