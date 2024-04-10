#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int mod = 1000000007;

int main() {
  int a, b;
  cin >> a >> b;
  long long ans = 0;
  for (int r = 1; r < b; ++r) {
    int cnt = a;
    ans += 1LL * cnt * r % mod + 1LL * cnt * (cnt + 1) / 2 % mod * r % mod * b % mod;
  }
  cout << ans % mod << endl;
  return 0;
}