// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    set<int> ss;
    for (char c : s) {
      if (c == '-') continue;
      ss.insert(c); 
    }
    if ((int) ss.size() == 1) {
      cout << n << '\n';
      continue;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int next = (i + 1) % n;
      if (s[i] == '-' || s[next] == '-') {
        ++ans;
      }
    }
    cout << ans << '\n';
  }
}