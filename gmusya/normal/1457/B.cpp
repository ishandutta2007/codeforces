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
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    int ans = n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int c = 1; c <= 100; c++) {
      int res = 0;
      for (int i = 0; i < n; i++) {
        if (a[i] == c)
          continue;
        i += k - 1;
        res++;
      }
      ans = min(ans, res);
    }
    cout << ans << '\n';
  }
  return 0;
}