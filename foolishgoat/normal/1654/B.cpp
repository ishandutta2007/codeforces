#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;
  vector<bool> exist(26, 0);
  int from = (int)s.size()-1;
  for (int i = (int)s.size()-1; i >= 0; --i) {
    int c = s[i] - 'a';
    if (!exist[c]) {
      from = i;
    }
    exist[c] = 1;
  }
  cout << s.substr(from) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}