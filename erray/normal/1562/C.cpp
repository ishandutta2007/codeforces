// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    string s;
    cin >> n >> s;
    if (count(s.begin(), s.end(), '0') == 0) {
      cout << 1 << ' ' << n - (n % 2) << ' ' << 1 << ' ' << n / 2 << '\n';
    } else {
      int p = 0;
      while (s[p] == '1') {
        ++p;
      }
      ++p;
      if (p > n / 2) {
        cout << 1 << ' ' << p << ' ' << 1 << ' ' << p - 1 << '\n';
      } else {
        cout << p << ' ' << n << ' ' << p + 1 << ' ' << n << '\n';
      }
    }

  }
}