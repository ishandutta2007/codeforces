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
    int go = lcm(s.size(), t.size());

    string tmp = s;
    while ((int) s.size() < go) {
      s += tmp;
    }

    tmp = t;
    while ((int) t.size() < go) {
      t += tmp;
    }

    cout << (t == s ? s : "-1"s) << '\n';
  }
}