// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = int(s.size());
    vector<int> ct(26);
    vector<int> lst(26, n);
    for (int i = 0; i < n; ++i) {
      int x = s[i] - 'a';
      ++ct[x];
      lst[x] = i;
    }
    vector<int> ord(26);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int x, int y) {
      return lst[x] < lst[y];
    });
    int sz = 0;
    for (int i = 0; i < 26; ++i) {
      sz += ((ct[ord[i]] / (i + 1)));
    }
    string t = s.substr(0, sz);
    string ps;
    vector<bool> vis(26);
    for (int i = 0; i < 26; ++i) {
      for (char c : t) {
        if (!vis[c - 'a']) {
          ps += c;  
        }
      }
      vis[ord[i]] = true; 
    }
    if (ps != s) {
      cout << -1 << '\n';
    } else {
      cout << t << ' ';
      for (int i = 0; i < 26; ++i) {
        if (ct[ord[i]] != 0) {
          cout << char('a' + ord[i]);
        }
      }
      cout << '\n';
    }
  }
}