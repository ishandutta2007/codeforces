// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s, t;
    cin >> s >> t;
    swap(s, t);
    int n = (int) s.size(), m = (int) t.size();
    int p = 0;
    bool ok = (s[0] == t[0]);
    for (int i = 0; i < m; ++i) {
      set<int> diff;
      while (p < n && t[i] != s[p]) {
        diff.insert(s[p]);
        ++p;
      }

      if (i > 0) {
        ok &= ((int) diff.empty() || ((int) diff.size() == 1 && *diff.begin() == t[i - 1]));
      }
      
      ok &= (p < n && s[p] == t[i]);
      ++p;
    }

    if (ok) {
      for (int i = p; i < n; ++i) {
        ok &= (s[i] == s[p - 1]);
      }
    }

    cout << (ok ? "YES" : "NO") << '\n';
  }
}