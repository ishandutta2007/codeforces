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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int sum = 0;
    for (int x : a) {
      sum += x;
    }
    if (sum % n) {
      cout << -1 << '\n';
      continue;
    }
    int cnt = 0;
    for (int x : a) {
      if (x > sum / n) {
        cnt++;
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}