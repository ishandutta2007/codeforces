#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int mex(const string &s) {
  set<int> se = {0, 1, 2};
  for (char ch : s) {
    if (se.find(ch - '0') != se.end()) {
      se.erase(ch - '0');
    }
  }
  return *se.begin();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int mx = mex(s);
    if (mx < 2) {
      cout << mx << '\n';
      continue;
    }
    int l = 0, r = s.size() - 1;
    while (s[l] == '1') {
      ++l;
    }
    while (s[r] == '1') {
      --r;
    }
    bool chk = false;
    for (int i = l; i <= r; i++) {
      if (s[i] == '1') {
        chk = true;
      }
    }
    if (chk) {
      cout << 2 << '\n';
    } else {
      cout << 1 << '\n';
    }
  }
  return 0;
}