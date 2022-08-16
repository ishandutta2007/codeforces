#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 59;


string s;
int dp[200001][3];

// type0
// type1
int rec(int idx, int mod) {
  if(idx == s.size()) return mod == 0;
  if(~dp[idx][mod]) return dp[idx][mod];
  int ret = 0;
  ret = max(ret, rec(idx + 1, (mod * 10 + s[idx] - '0') % 3));
  ret = max(ret, rec(idx + 1, (s[idx] - '0') % 3) + (mod == 0));
  return dp[idx][mod] = ret;
}

int main() {
  cin >> s;
  memset(dp, -1, sizeof(dp));
  cout << rec(1, (s[0] - '0') % 3) << endl;
}