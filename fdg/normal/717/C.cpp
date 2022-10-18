#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i)
    cin >> v[i];
  sort(v.begin(), v.end());
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = (1LL * v[i] * v[n - 1 - i] + ans) % 10007;
  }
  cout << ans << endl;
  return 0;
}