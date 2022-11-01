#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  while (true) {
    pair <int, int> cur = {-1, -1};
    for (int i = 0; i < (int) s.size(); i++) {
      if ((i && s[i] == s[i - 1] + 1) || (i + 1 < (int) s.size() && s[i] == s[i + 1] + 1))
        cur = max(cur, {s[i] - 'a', i});
    }
    if (cur.first == -1)
      break;
    string t;
    for (int i = 0; i < cur.second; i++)
      t += s[i];
    for (int i = cur.second + 1; i < (int) s.size(); i++)
      t += s[i];
    swap(s, t);
  }
  cout << n - (int) s.size();
  return 0;
}