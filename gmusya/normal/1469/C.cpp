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
    vector <int> h(n);
    for (int i = 0; i < n; i++)
      cin >> h[i];
    vector <int> l(n), r(n);
    l[0] = h[0];
    r[0] = h[0];
    for (int i = 1; i < n; i++) {
      l[i] = max(h[i], l[i - 1] - (k - 1));
      r[i] = min(h[i] + k - 1, r[i - 1] + (k - 1));
      if (l[i] > r[i]) {
        l.back() = 1;
        r.back() = 0;
        break;
      }
    }
    if (l.back() > r.back() || l.back() > h.back())
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}