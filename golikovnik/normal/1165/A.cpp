#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;
using std::string;

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, x, y;
  cin >> n >> x >> y;
  string s;
  cin >> s;
  std::reverse(s.begin(), s.end());
  string need = string(x - y - 1, '0') + string(1, '1') + string(y, '0');
  std::reverse(need.begin(), need.end());
  int result = 0;
  for (int i = 0; i < x; i++) {
    result += need[i] != s[i];
  }
  cout << result << "\n";
  return 0;
}