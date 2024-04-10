// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    string s;
    cin >> n >> s;
    int p = 0;
    while (p < n && s[p] == '?') {
      ++p;
    }
    char c = (p < n ? s[p] : 'R');                     
    auto Rev = [](char c, int r = 1) -> char { return ((c == 'B') ^ r ^ 1 ? 'R' : 'B'); };
    s[0] = Rev(c, (p - c) & 1);
    for (int i = 1; i < n; ++i) {
      if (s[i] == '?') {
        s[i] = Rev(s[i - 1]);
      }
    } 
    cout << s << '\n';
  }
}