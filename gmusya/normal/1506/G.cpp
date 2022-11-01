#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    vvi a(26);
    int n = s.size();
    for (int i = 0; i < n; i++) {
      a[s[i] - 'a'].push_back(i);
    }
    vector <bool> used(26, false);
    int cnt_unused = 26;
    for (int i = 0; i < 26; i++) {
      if (a[i].empty()) {
        used[i] = true;
        cnt_unused--;
      }
    }
    int pos = -1;
    string ans = "";
    while (cnt_unused--) {
      for (int first = 25; first >= 0; first--) {
        if (used[first]) {
          continue;
        }
        int pos_new = *lower_bound(a[first].begin(), a[first].end(), pos);
        bool can = true;
        for (int second = 0; second < 26; second++) {
          if (used[second]) {
            continue;
          }
          if (a[second].back() < pos_new) {
            can = false;
            break;
          }
        }
        if (can) {
          ans += (char)('a' + first);
          used[first] = true;
          pos = pos_new;
          break;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}