#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, K;
  string S, T;

  cin >> N >> K;
  cin >> S >> T;

  int64 dp[4] = {};
  int64 ret = 0;

  if(S[0] == 'a') {
    if(T[0] == 'a') {
      dp[3] = 1;
      K--;
      ++ret;
    } else {
      dp[1] = 1;
      K--;
      ++ret;
      if(K >= 1) {
        dp[2] = 1;
        K--;
        ++ret;
      }
    }
  } else {
    dp[3] = 1;
    K--;
    ++ret;
  }


  for(int z = 1; z < N; z++) {
    int64 nxtdp[4] = {};
    int64 nxtweight[4] = {};

    for(int j = 0; j <= 3; j++) {
      bool process = false;
      for(char i = 'a'; i <= 'b'; i++) {
        int nxtbit = 0;
        if(j & 1) { // S
          if(S[z] > i) continue;
          if(S[z] == i) nxtbit |= 1;
        }
        if(j & 2) { // T
          if(T[z] < i) continue;
          if(T[z] == i) nxtbit |= 2;
        }

        if(process) {
          if(K == 0) continue;
          int64 add = min< int64 >(dp[j], K);
          K -= add;
          nxtdp[nxtbit] += add;
          ret += add;
        } else {
          process = true;
          nxtdp[nxtbit] += dp[j];
          ret += dp[j];
        }
      }
    }
    swap(nxtdp, dp);
  }

  cout << ret << endl;
}