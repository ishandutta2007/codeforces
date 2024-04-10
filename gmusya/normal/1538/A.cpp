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
    vector <int> b;
    for (int i = 0; i < n; i++) {
      if (a[i] == 1 || a[i] == n) {
        b.push_back(i);
      }
    }
    int ans = b[1] + 1;
    ans = min(n - b[0], ans);
    ans = min(n - b[1] + b[0] + 1, ans);
    cout << ans << '\n';
  }
  return 0;
}