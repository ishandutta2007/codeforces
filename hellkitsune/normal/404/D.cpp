#include <cstdio>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

using namespace std;

const int mod = 1000000007;
int dp[5], dpb[5];

int main()
{
  string s;
  cin >> s;
  int n = s.length();
  REP(i, 5) dp[i] = 0;
  switch (s[0]) {
    case '0': {dp[0] = 1; break;}
    case '1': {dp[4] = 1; break;}
    case '*': {dp[3] = 1; break;}
    case '?': {dp[0] = dp[4] = dp[3] = 1; break;}
  }
  for (int i = 1; i < n; ++i) {
    switch (s[i]) {
      case '?': {
        dpb[0] = (dp[0] + dp[1]) % mod;
        dpb[1] = dp[3];
        dpb[2] = dp[3];
        dpb[3] = (dp[3] + dp[4]) % mod;
        dpb[3] = (dpb[3] + dp[2]) % mod;
        dpb[4] = (dp[0] + dp[1]) % mod;
        break;
      }
      case '0': {
        dpb[0] = (dp[0] + dp[1]) % mod;
        dpb[1] = dpb[2] = dpb[3] = dpb[4] = 0;
        break;
      }
      case '1': {
        dpb[1] = dp[3];
        dpb[4] = (dp[0] + dp[1]) % mod;
        dpb[0] = dpb[2] = dpb[3] = 0;
        break;
      }
      case '2': {
        dpb[2] = dp[3];
        dpb[0] = dpb[1] = dpb[3] = dpb[4] = 0;
        break;
      }
      case '*': {
        dpb[3] = (dp[3] + dp[4]) % mod;
        dpb[3] = (dpb[3] + dp[2]) % mod;
        dpb[0] = dpb[1] = dpb[2] = dpb[4] = 0;
        break;
      }
    }
    REP(i, 5)
      dp[i] = dpb[i];
  }
  int ans = (dp[0] + dp[1]) % mod;
  ans = (ans + dp[3]) % mod;
  cout << ans << endl;
  return 0;
}