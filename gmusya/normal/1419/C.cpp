#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    int cnt = 0;
    for (int i = 0; i < n; i++)
      cnt += (a[i] == x);
    if (cnt == n) {
      cout << 0 << '\n';
      continue;
    }
    if (cnt >= 1) {
      cout << 1 << '\n';
      continue;
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
      sum += a[i];
    if (sum % n == 0 && sum / n == x) {
      cout << 1 << '\n';
      continue;
    }
    cout << 2 << '\n';
  }
  return 0;
}