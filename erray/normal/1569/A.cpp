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
    if (*max_element(s.begin(), s.end()) == *min_element(s.begin(), s.end())) {
      cout << -1 << ' ' << -1 << '\n';
    } else {
      int p = 0;
      while (s[p] == s[p + 1]) {
        ++p;
      }
      cout << p + 1 << ' ' << p + 2 << '\n';
    }
  }
}