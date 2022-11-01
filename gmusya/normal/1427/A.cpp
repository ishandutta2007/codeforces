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
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if (!sum) {
      cout << "NO\n";
      continue;
    }
    if (sum > 0)
      sort(a.rbegin(), a.rend());
    else
      sort(a.begin(), a.end());
    cout << "YES\n";
    for (int x : a)
      cout << x << ' ';
    cout << '\n';
  }
  return 0;
}