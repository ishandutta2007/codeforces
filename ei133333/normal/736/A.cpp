#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main()
{
  int64 N;
  cin >> N;
  int64 dp[1000];
  dp[1] = 1;
  dp[2] = 1;
  for(int i = 3; i < 1000; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  int ret = 1;
  while(dp[ret] <= N) ++ret;
  cout << ret-3 << endl;
}