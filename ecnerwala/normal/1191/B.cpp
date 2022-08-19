#include<bits/stdc++.h>
using namespace std;

int main() {
  map<char, vector<int>> mp;
  for (int i = 0; i < 3; i++) {
    int v; char c; cin >> v >> c; mp[c].push_back(v);
  }
  int ans = 2;
  for (auto it : mp) {
    auto v = it.second;
    if (v.size() < 2) continue;
    sort(v.begin(), v.end());
    if (v.size() == 3 && v[0] == v[2]) ans = 0;
    else if (v.size() == 3 && v[1] == v[0] + 1 && v[2] == v[1] + 1) ans = 0;
    else if (v[1] - v[0] <= 2) ans = min(ans, 1);
    else if (v.size() == 3 && v[2] - v[1] <= 2) ans = min(ans, 1);
  }
  cout << ans << '\n';
}