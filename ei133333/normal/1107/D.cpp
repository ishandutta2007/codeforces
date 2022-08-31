#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

int conv[256];

int N;
char S[5200];
bool v[5200][5200];
int dp[5200][5200];

int main() {
  int ptr = 0;
  for(char a = '0'; a <= '9'; a++) conv[a] = ptr++;
  for(char a = 'A'; a <= 'F'; a++) conv[a] = ptr++;
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf(" %s", S);
    for(int j = 0; j < N / 4; j++) {
      v[i][j * 4 + 0] = conv[S[j]] & 8;
      v[i][j * 4 + 1] = conv[S[j]] & 4;
      v[i][j * 4 + 2] = conv[S[j]] & 2;
      v[i][j * 4 + 3] = conv[S[j]] & 1;
    }
  }


  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(i == 0 || j == 0) {
        dp[i][j] = 1;
      } else {
        dp[i][j] = INF;
        if(v[i - 1][j - 1] == v[i][j]) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
        else dp[i][j] = 1;
        if(v[i - 1][j] == v[i][j]) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
        else dp[i][j] = 1;
        if(v[i][j - 1] == v[i][j]) dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
        else dp[i][j] = 1;
      }
    }
  }

  for(int i = N; i >= 1; i--) {
    if(N % i == 0) {
      int ret = INF;
      for(int j = i - 1; j < N; j += i) {
        for(int k = i - 1; k < N; k += i) {
          ret = min(ret, dp[j][k]);
        }
      }
      if(ret >= i) {
        cout << i << endl;
        return 0;
      }
    }
  }
}