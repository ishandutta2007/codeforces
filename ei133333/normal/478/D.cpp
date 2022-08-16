#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const int mod = 1e9 + 7;

int R, G;
int dp[400001];

int main()
{
  cin >> R >> G;
  dp[0] = 1;

  int last = 0;
  for(int level = 1; level * (level + 1) / 2 <= R + G; level++) {
    last = level * (level + 1) / 2;
    for(int i = min(last, G); i >= 0; i--) {
      (dp[i + level] += dp[i]) %= mod;
    }
  }

  int64 ret = 0;
  for(int i = 0; i <= G; i++) {
    if(last - i >= 0 && last - i <= R) ret += dp[i];
  }
  cout << ret % mod << endl;

}