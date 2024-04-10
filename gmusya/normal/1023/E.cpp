#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  string ans1 = "";
  int x = 1, y = 1;
  while ((n - x) + (n - y) >= n) {
    if (x + 1 <= n) {
      cout << "? " << x + 1 << ' ' << y << ' ' << n << ' ' << n << endl;
      string res;
      cin >> res;
      if (res == "YES") {
        x++;
        ans1 += "D";
        continue;
      }
    }
    y++;
    ans1 += "R";
  }
  string ans2 = "";
  x = n, y = n;
  while ((x - 1) + (y - 1) >= n) {
      if (y - 1 > 0) {
      cout << "? " << 1 << ' ' << 1 << ' ' << x << ' ' << y - 1 << endl;
      string res;
      cin >> res;
      if (res == "YES") {
        ans2 += "R";
        y--;
        continue;
      }
    }
    x--;
    ans2 += "D";
  }
  cout << "! " << ans1;
  reverse(ans2.begin(), ans2.end());
  cout << ans2;
  return 0;
}