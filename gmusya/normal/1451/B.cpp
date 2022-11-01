#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
      char c;
      cin >> c;
      a[i] = c - '0';
    }
    while (q--) {
      int l, r;
      cin >> l >> r;
      l--, r--;
      int pos = l;
      bool flag = false;
      for (int i = 0; i < n && pos <= r; i++) {
        if (a[i] != a[pos]) {
          if (pos > l)
            flag = true;
          continue;
        }
        if (pos == r) {
          if (!flag)
            flag = true;
          else
            pos++;
          continue;
        }
        pos++;
      }
      if (pos > r && flag)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}