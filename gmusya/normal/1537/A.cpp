#include <iostream>
#include <vector>

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
    int sum = -n;
    for (int i = 0; i < n; i++) {
      sum += a[i];
    }
    if (sum < 0) {
      cout << 1 << '\n';
    } else {
      cout << sum << '\n';
    }
  }
  return 0;
}