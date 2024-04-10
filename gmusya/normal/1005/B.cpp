#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  int l = 0;
  int n = s.size(), m = t.size();
  while (l < min(n, m) && s[n - l - 1] == t[m - l - 1])
    l++;
  cout << n + m - 2 * l;
  return 0;
}