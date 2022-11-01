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
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int r = i;
      while (r < n && a[r] == a[i])
        r++;
      ans = max(ans, r - i);
      i = r - 1;
    }
    cout << ans << '\n';
  }
  return 0;
}