#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, z;
  cin >> n >> z;
  vector <int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  int m = n / 2;
  multiset <int> left, right;
  for (int i = 0; i < m; i++)
    left.insert(a[i]);
  for (int i = n - 1; i >= n - m; i--)
    right.insert(a[i]);
  int ans = 0;
  while (!left.empty()) {
    int v = *left.begin();
    left.erase(left.begin());
    auto it = right.lower_bound(v + z);
    if (it == right.end())
      break;
    ans++;
    right.erase(it);
  }
  cout << ans;
  return 0;
}