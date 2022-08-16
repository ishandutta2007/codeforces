#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;


string s[2];
int dp[103][1 << 2];

int rec(int x, int bit) {
  if(x == s[0].size()) return 0;
  if(~dp[x][bit]) return dp[x][bit];
  int ret = rec(x + 1, 0);
  if(x + 1 < s[0].size()) {
    for(int i = 0; i < (1 << 2); i++) {
      if((i >> 0) & 1) {
        if((bit >> 0) & 1) continue;
        if(s[0][x] == 'X') continue;
      }
      if((i >> 1) & 1) {
        if((bit >> 1) & 1) continue;
        if(s[1][x] == 'X') continue;
      }
      for(int j = 0; j < (1 << 2); j++) {
        if((j >> 0) & 1) {
          if(s[0][x + 1] == 'X') continue;
        }
        if((j >> 1) & 1) {
          if(s[1][x + 1] == 'X') continue;
        }
        if(__builtin_popcount(i) + __builtin_popcount(j) != 3) {
          continue;
        }
        ret = max(ret, rec(x + 1, j) + 1);
      }
    }
  }
  return dp[x][bit] = ret;
}

int main() {
  memset(dp, -1, sizeof(dp));
  cin >> s[0] >> s[1];
  cout << rec(0, 0) << endl;
}