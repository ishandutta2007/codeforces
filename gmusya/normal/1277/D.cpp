#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    set <string> s0, s1;
    int n;
    cin >> n;
    vi c00, c01, c10, c11;
    vector <string> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
      char a = s[i][0], b = s[i].back();
      if (a == '0' && b == '0')
        c00.push_back(i);
      if (a == '0' && b == '1') {
        string tmp = s[i];
        reverse(tmp.begin(), tmp.end());
        s0.insert(tmp);
        c01.push_back(i);
      }
      if (a == '1' && b == '0') {
        string tmp = s[i];
        reverse(tmp.begin(), tmp.end());
        s1.insert(tmp);
        c10.push_back(i);
      }
      if (a == '1' && b == '1')
        c11.push_back(i);
    }
    if (!c00.empty() && !c11.empty() && c01.empty() && c10.empty()) {
      cout << -1 << '\n';
      continue;
    }
    vi ans;
    int diff = (int)c01.size() - (int)c10.size();
    for (int id : c01) {
      if (diff <= 1)
        break;
      if (s1.find(s[id]) != s1.end())
        continue;
      ans.push_back(id);
      diff -= 2;
    }
    for (int id : c10) {
      if (diff >= -1)
        break;
      if (s0.find(s[id]) != s0.end())
        continue;
      ans.push_back(id);
      diff += 2;
    }
    if (diff < -1 || diff > 1) {
      cout << -1 << '\n';
      continue;
    }
    cout << ans.size() << '\n';
    for (int x : ans)
      cout << x + 1 << ' ';
    cout << '\n';
  }
  return 0;
}