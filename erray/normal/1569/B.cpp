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
    array<vector<int>, 2> pos;
    for (int i = 0; i < n; ++i) {
      pos[(s[i] - '0' - 1) ^ 1].push_back(i);
    }
    if (!pos[0].empty() && int(pos[0].size()) < 3) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    vector<string> ans(n, string(n, '='));
    for (int i = 0; i < n; ++i) {
      ans[i][i] = 'X';
    }

    for (int i = 0; i < int(pos[0].size()); ++i) {
      int j = (i + 1) % int(pos[0].size());
      ans[pos[0][i]][pos[0][j]] = '+';
      ans[pos[0][j]][pos[0][i]] = '-'; 
    }
    
    for (auto e : ans) {
      cout << e << '\n';
    }
  }
}