#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

string s;
int64 dp[20][20];

int64 rec(int idx, int sum, bool isfree) {
  if(sum >= 4) return 0;
  if(idx == -1) return 1;
  if(isfree && ~dp[idx][sum]) return dp[idx][sum];
  int64 ret = 0;
  for(int i = 0; i <= (isfree ? 9 : s[idx] - '0'); i++) {
    ret += rec(idx - 1, sum + (i > 0), isfree | (s[idx] - '0' != i));
  }
  if(isfree) dp[idx][sum] = ret;
  return ret;
}

int64 solve(int64 x) {
  s = to_string(x);
  reverse(begin(s), end(s));
  return rec((int) s.size() - 1, 0, false);
}

int main() {
  memset(dp, -1, sizeof(dp));
  int T;
  cin >> T;
  while(T--) {
    int64 L, R;
    cin >> L >> R;
    --L;
    cout << solve(R) - solve(L) << endl;
  }
}