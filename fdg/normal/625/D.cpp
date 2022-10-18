#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <set>
#include <queue>
#include <map>

using namespace std;

char s[100005];
bool dp[2][2][100005];

struct state {
  int toL, fromR, s;
};

state pr[2][2][100005];

void solve(int n, int toL) {
  memset(dp, 0, sizeof(dp));
  if (n % 2 == 0) {
    dp[toL][0][0] = true;
    for (int i = 0; i < n / 2; ++i) {
      for (int toL = 0; toL < 2; ++toL) {
        for (int fromR = 0; fromR < 2; ++fromR) {
          if (!dp[toL][fromR][i]) continue;
          for (int sum = (i == 0); sum < 19; ++sum) {
            for (int newL = 0; newL < 2; ++newL) {
              if ((sum + fromR) % 10 == s[n - 1 - i] - '0'
                  && (sum + newL) % 10 == s[i] - '0'
                  && (sum + newL) / 10 == toL) {
                dp[newL][(sum + fromR) / 10][i + 1] = true;
                pr[newL][(sum + fromR) / 10][i + 1] = state{toL, fromR, sum};
              } 
            }
          }
        }
      }
    }

    if (dp[0][0][n / 2] || dp[1][1][n / 2]) {
      int toL = 0, fromR = 0;
      if (!dp[toL][fromR][n / 2]) toL = fromR = 1;

      for (int i = n / 2; i > 0; --i) {
        state st = pr[toL][fromR][i];
        int d1 = min(st.s, 9), d2 = st.s - d1;
        s[i - 1] = d1 + '0';
        s[n - i] = d2 + '0';

        // cout << d1 << " " << d2 << endl;

        toL = st.toL; fromR = st.fromR;
      }

      puts(s);
      exit(0);
    }
  } else {
    dp[toL][0][0] = true;
    for (int i = 0; i < n / 2; ++i) {
      for (int toL = 0; toL < 2; ++toL) {
        for (int fromR = 0; fromR < 2; ++fromR) {
          if (!dp[toL][fromR][i]) continue;
          for (int sum = (i == 0); sum < 19; ++sum) {
            for (int newL = 0; newL < 2; ++newL) {
              if ((sum + fromR) % 10 == s[n - 1 - i] - '0'
                  && (sum + newL) % 10 == s[i] - '0'
                  && (sum + newL) / 10 == toL) {
                dp[newL][(sum + fromR) / 10][i + 1] = true;
                pr[newL][(sum + fromR) / 10][i + 1] = state{toL, fromR, sum};
              } 
            }
          }
        }
      }
    }

    for (int toL = 0; toL < 2; ++toL) {
      for (int fromR = 0; fromR < 2; ++fromR) {
        if (!dp[toL][fromR][n / 2]) continue;

        for (int sum = 0; sum < 19; sum += 2) {
          if ((sum + fromR) % 10 == s[n / 2] - '0' && (sum + fromR) / 10 == toL) {
            s[n / 2] = sum / 2 + '0';
            for (int i = n / 2; i > 0; --i) {
              state st = pr[toL][fromR][i];
              int d1 = min(st.s, 9), d2 = st.s - d1;
              s[i - 1] = d1 + '0';
              s[n - i] = d2 + '0';

              // cout << d1 << " " << d2 << endl;

              toL = st.toL; fromR = st.fromR;
            }

            puts(s);
            exit(0);
          }
        }
      }
    }
  }
}

int main() {
  gets(s);
  int n = strlen(s);

  solve(n, 0);
  if (s[0] == '1') {
    for (int i = 1; i < n; ++i)
      s[i - 1] = s[i];
    --n; s[n] = '\0';
    solve(n, 1);
  }

  puts("0");

  return 0;
}