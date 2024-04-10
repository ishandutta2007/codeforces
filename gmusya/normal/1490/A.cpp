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
    for (int i = 0; i < n; i++)
      cin >> a[i];
    int cnt = 0;
    for (int i = 0; i + 1 < n; i++) {
      int x = min(a[i], a[i + 1]);
      int y = max(a[i], a[i + 1]);
      while (2 * x < y) {
        x *= 2;
        cnt++;
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}