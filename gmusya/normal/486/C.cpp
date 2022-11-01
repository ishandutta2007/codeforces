#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, p;
  cin >> n >> p;
  string s;
  cin >> s;
  int ans = 0;
  p = min(p, n - p + 1);
  p--;
  int l = p, r = p;
  for (int i = 0; i + i + 1 < n; i++) {
    int x = abs(s[i] - s[n - i - 1]);
    if (x) l = min(l, i);
    if (x) r = max(r, i);
    ans += min(x, 26 - x);
  }
  ans += (r - l) + min(r - p, p - l);
  cout << ans;
  return 0;
}