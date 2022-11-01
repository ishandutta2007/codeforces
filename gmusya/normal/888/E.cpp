#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector <int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  if (n == 1) {
    cout << a[0] % m;
    return 0;
  }
  int k = n / 2;
  vector <int> b, c;
  for (int i = 0; i < k; i++)
    b.push_back(a[i]);
  for (int i = k; i < n; i++)
    c.push_back(a[i]);
  vector <int> left;
  for (int mask = 0; mask < (1 << (int) b.size()); mask++) {
    int sum = 0;
    for (int i = 0; i < (int) b.size(); i++)
      if (mask & (1 << i)) {
        sum += b[i];
        if (sum >= m)
          sum %= m;
      }
    left.push_back(sum);
  }
  vector <int> right;
  for (int mask = 0; mask < (1 << (int) c.size()); mask++) {
    int sum = 0;
    for (int i = 0; i < (int) c.size(); i++)
      if (mask & (1 << i)) {
        sum += c[i];
        if (sum >= m)
          sum %= m;
      }
    right.push_back(sum);
  }
  sort(left.begin(), left.end());
  int ans = 0;
  for (int s : right) {
    ans = max(ans, (s + left.back()) % m);
    auto it = lower_bound(left.begin(), left.end(), m - s);
    if (it == left.begin())
      continue;
    it--;
    ans = max(ans, (s + *it) % m);
  }
  for (int s : left)
    ans = max(ans, s);
  for (int s : right)
    ans = max(ans, s);
  cout << ans;
  return 0;
}