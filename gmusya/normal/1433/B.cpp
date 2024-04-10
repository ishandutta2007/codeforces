#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n + 2);
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    vector <int> sum(n + 2);
    for (int i = 1; i <= n + 1; i++)
      sum[i] = sum[i - 1] + a[i];
    int l = 1e9, r = -1e9;
    for (int i = 1; i <= n; i++) {
      if (!a[i]) continue;
      l = min(l, i);
      r = max(r, i);
    }
    cout << (r - l + 1) - sum[r] - sum[l - 1] << '\n';
  }
  return 0;
}