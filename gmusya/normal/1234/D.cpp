#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string str;
  cin >> str;
  vector <set <int>> s(26);
  for (int i = 0; i < (int)str.size(); i++)
    s[str[i] - 'a'].insert(i);
  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int pos;
      char c;
      cin >> pos >> c;
      pos--;
      s[str[pos] - 'a'].erase(pos);
      str[pos] = c;
      s[str[pos] - 'a'].insert(pos);
    }
    if (type == 2) {
      int l, r;
      cin >> l >> r;
      l--, r--;
      int ans = 0;
      for (int i = 0; i < 26; i++)
      ans += (s[i].lower_bound(l) != s[i].upper_bound(r));
      cout << ans << '\n';
    }
  }
  return 0;
}