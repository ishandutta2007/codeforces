#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    while (!s.empty() && (s.back() - '0') % 2 == 0)
      s.pop_back();
    if (s.empty()) {
      cout << -1 << '\n';
      continue;
    }
    int pos = -1;
    for (int i = 0; i + 1 < (int)s.size(); i++)
      if ((s[i] - '0') % 2)
        pos = i;
    if (pos == -1) {
      cout << -1 << '\n';
      continue;
    }
    cout << s[pos] << s.back() << '\n';
  }
  return 0;
}