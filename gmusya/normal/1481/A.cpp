#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;
    string s;
    cin >> s;
    int l = 0, r = 0, u = 0, d = 0;
    for (char c : s) {
      if (c == 'L')
        l++;
      if (c == 'R')
        r++;
      if (c == 'U')
        u++;
      if (c == 'D')
        d++;
    }
    if (-l <= x && x <= r && -d <= y && y <= u)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}