#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string a, b;
    cin >> a >> b;
    int ans = 0;
    for (int len = (int)a.size(); len >= 0 && ans == 0; len--) {
      for (int l1 = 0; l1 + len <= (int)a.size() && ans == 0; l1++) {
        for (int l2 = 0; l2 + len <= (int)b.size() && ans == 0; l2++) {
          bool flag = true;
          for (int i = 0; i < len; i++) {
            if (a[l1 + i] != b[l2 + i]) {
              flag = false;
              break;
            }
          }
          if (flag) {
            ans = len;
          }
        }
      }
    }
    cout << (int)a.size() + (int)b.size() - 2 * ans << '\n';
  }
  return 0;
}