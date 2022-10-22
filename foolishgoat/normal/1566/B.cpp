#include <bits/stdc++.h>

using namespace std;


void solve() {
  string s;
  cin >> s;
  int n = s.size();
  int l = 0, r = n-1;
  while (l <= r && s[l] != '0') ++l;
  while (l <= r && s[r] != '0') --r;
  if (l > r) {
    cout << "0\n";
    return;
  } else {
    int cnt = 0;
    for (int i = l; i < r; ++i) {
      cnt += s[i] == '1';
    }
    if (cnt) {
      cout << "2\n";
    } else {
      cout << "1\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  for (int tt = 1; tt <= tc; ++tt) {
    solve();
  }
  return 0;
}