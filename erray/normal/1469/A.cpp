// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    vector<int> pos(256);
    for (int i = 0; i < (int) s.size(); ++i) {
      pos[s[i]] = i;
    }

    cout << ((int) s.size() % 2 == 0 &&  pos['('] != (int) s.size() - 1 && pos[')'] != 0 ? "YES" : "NO") << '\n';
  }
}