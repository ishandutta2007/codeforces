#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int ans = (s[0] - '1') * 10 + n * (n + 1) / 2;
    cout << ans << '\n';
  }
  return 0;
}