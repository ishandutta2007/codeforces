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
    int n = (int) s.size();
    vector<vector<int>> pos(256);
    for (int i = 0; i < n; ++i) {
      pos[s[i]].push_back(i);
    }
    int ans = 0;
    for (int c = 'a'; c < 'z' + 1; ++c) {
      vector<bool> act(n, false);
      
      for (auto el : pos[c]) {
        act[el] = true;
      }

      for (int i = 0; i < n; ++i) {
        if (!act[i]) {
          continue;  
        }

        bool no = false;
        for (int j = -2; j < 0; ++j) {
          no |= (i + j >= 0 && act[i + j]);
        }

        if (no) {
          act[i] = false;
          ++ans;  
        }
      }
    }
    cout << ans << '\n';
  }
}