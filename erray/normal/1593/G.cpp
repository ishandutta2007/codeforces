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
    vector<int> o(n + 1);
    vector<int> e(n + 1);
    for (int i = 0; i < n; ++i) {
      o[i + 1] += o[i];
      e[i + 1] += e[i];
      if (s[i] == '[' || s[i] == ']') {
        (i % 2 ? o : e)[i + 1] += 1;
      }
    }
    
    int q;
    cin >> q;
    while (q--) {
      int l, r;
      cin >> l >> r;
      --l;
      cout << abs((o[r] - o[l]) - (e[r] - e[l])) << '\n';
    }
  } 
}