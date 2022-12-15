#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 505;
const int mod = 998244353;

int dp[ms][ms];
int c[ms];

int solve(int a, int b) {
  if(a == b) return 1;
  if(~dp[a][b]) return dp[a][b];
  int &ans = dp[a][b] = 0;
  ans = 0;
  int lo = a+1;
  for(int i = a+2; i <= b; i++) { 
    if(c[i] < c[lo]) lo = i;
  }
  int ansLeft = 0;
  int ansRight = 0;
  for(int i = a; i < lo; i++) {
    ansLeft = (ansLeft + solve(a, i) * solve(i, lo-1)) % mod;
  }
  for(int i = lo; i <= b; i++) {
    ansRight = (ansRight + solve(lo, i) * solve(i, b)) % mod;
  }
//cout << ansLeft << ' ' << ansRight << ' ' << a << ' ' << b << endl;
  return ans = ansLeft * ansRight % mod;
}

main() {
  memset(dp, -1, sizeof dp);
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= m; i++) cin >> c[i];
  cout << solve(0, n) << '\n';
}