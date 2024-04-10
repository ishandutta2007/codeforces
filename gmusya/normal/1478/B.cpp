#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int q, d;
    cin >> q >> d;
    while (q--) {
      int c;
      cin >> c;
      if (c >= 100) {
        cout << "YES\n";
        continue;
      }
      bool ans = false;
      while (c >= d) {
        int k = c;
        bool flag = false;
        while (k) {
          flag |= (k % 10 == d);
          k /= 10;
        }
        if (flag) {
          ans = true;
          break;
        }
        c -= d;
      }
      if (ans)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}