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
    int cnt = 0;
    for (int i = 0; i < n - cnt; ++i) {
      if (s[i] == 't') {
        s.erase(s.begin() + i);
        --i;
        ++cnt;
        s += 't';
      }
    }
    cout << s << '\n';
  }
}