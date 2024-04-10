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
    vector <int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    long long sum = 0;
    for (int i = 0; i + 1 < n; i++)
      sum += abs(a[i + 1] - a[i]);
    long long cur = max(abs(a[1] - a[0]), abs(a[n - 1] - a[n - 2]));
    for (int i = 1; i + 1 < n; i++) {
      long long tmp = abs(a[i] - a[i + 1]) + abs(a[i] - a[i - 1]) - abs(a[i - 1] - a[i + 1]);
      cur = max(tmp, cur);
    }
    cout << sum - cur << '\n';
  }
  return 0;
}