#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int mod = 1000000007;

int sums[100005], pw[100005];

int main() {
  ios::sync_with_stdio(false);
  string s;
  cin >> s;

  int n = s.size();
  int sum = 0, cur = 1; pw[0] = 1;
  for (int i = 1; i <= n; ++i) {
    sum = (sum + 1LL * i * cur) % mod;
    cur = 10LL * cur % mod;
    pw[i] = cur;
    sums[i] = sum;
  }

  int ans = 0;
  reverse(s.begin(), s.end());
  for (int i = 0; i < n; ++i) {
    if (i > 0)
      ans = (ans + 1LL * (s[i] - '0') * sums[i]) % mod;
    if (i + 1 < n) {
      int rem = n - 1 - i, r1 = rem + 1;
      if (rem & 1) r1 /= 2;
      else rem /= 2;
      ans = (ans + 1LL * (s[i] - '0') * pw[i] % mod * rem % mod * r1) % mod;
    }
    // cout << ans << endl;
  }
  cout << ans << endl;

  return 0;
}