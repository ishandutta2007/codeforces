#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> h(n);
    for (int i = 0; i < n; i++)
      cin >> h[i];
    bool flag = true;
    for (int i = 0; i + 1 < n; i++) {
      if (m < 0)
        flag = false;
      int newh = max(h[i + 1] - k, 0);
      m += h[i] - newh;
    }
    if (m < 0)
      flag = false;
    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}