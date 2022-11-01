#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

map <pair <int, int>, ull> dp;

ull solve(int n, int h) {
  if (!n)
    return (h == 0);
  if (h < 0)
    return 0;
  if (dp.find({n, h}) != dp.end())
    return dp[{n, h}];
  ull res = 0;
  for (int l = 0; l < n; l++) {
    for (int hl = 0; hl + 1 < h; hl++)
      res += 2 * solve(l, hl) * solve(n - 1 - l, h - 1);
    res += solve(l, h - 1) * solve(n - 1 - l, h - 1);
  }
  return dp[{n, h}] = res;
}

int main() {
  int n, h;
  cin >> n >> h;
  ull res = 0;
  for (int i = h; i <= n; i++)
    res += solve(n, i);
  cout << res;
  return 0;
}