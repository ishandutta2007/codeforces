#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector <int> h(n);
    for (int i = 0; i < n; i++)
      cin >> h[i];
    int ans = -2;
    k = min(k, 10000);
    while (k--) {
      ans = -2;
      for (int i = 0; i + 1 < n; i++)
        if (h[i] < h[i + 1]) {
          h[i]++;
          ans = i;
          break;
        }
    }
    cout << ans + 1 << '\n';
  }
  return 0;
}