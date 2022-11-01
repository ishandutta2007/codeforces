#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int c0, c1, h;
    cin >> c0 >> c1 >> h;
    c0 = min(c0, c1 + h);
    c1 = min(c1, c0 + h);
    string s;
    cin >> s;
    int ans = 0;
    for (char c : s) {
      if (c == '0')
        ans += c0;
      else
        ans += c1;
    }
    cout << ans << '\n';
  }
  return 0;
}