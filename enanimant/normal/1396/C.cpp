// August 30, 2020
// https://codeforces.com/contest/1396/problem/C

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1396C.cpp -o a.out && a.out
*/


#include <bits/stdc++.h>

using namespace std;


const long long INF = (long long) 9e18;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif
  
  
  int n;
  long long r1, r2, r3, d;
  cin >> n >> r1 >> r2 >> r3 >> d;
  long long kill_one = min(r1, r3);
  vector<int> a(n);
  vector<long long> once(n), twice(n);
  vector<long long> f1(n + 1, 0), f2(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    once[i] = kill_one * a[i] + r3;
    twice[i] = min(once[i], min(r2 + kill_one, r1 * (a[i] + 2)));
    f1[i + 1] = f1[i] + once[i];
    f2[i + 1] = f2[i] + twice[i];
  }
  vector<vector<long long>> dp(n + 1, vector<long long>(2, INF));
  dp[0][0] = -d;
  long long ans = INF;
  for (int i = 0; i < n; i++) {
    {
      long long res = dp[i][0] + d + once[i];
      res = min(res, dp[i][1] + d + twice[i] + d + kill_one + d);
      res = min(res, dp[i][0] + d + twice[i] + d + d);
      dp[i + 1][0] = res;
    }
    {
      dp[i + 1][1] = dp[i][0] + d + min(r2, r1 * (a[i] + 1));
    }
    if (i < n - 1) {
      ans = min(ans, dp[i + 1][0] + f2[n - 1] - f2[i + 1] + once[n - 1] + d * (2 * (n - (i + 1)) - 1));
    } else {
      ans = min(ans, dp[i + 1][0]);
    }
  }
  cout << ans << '\n';
  
  
  return 0;
}