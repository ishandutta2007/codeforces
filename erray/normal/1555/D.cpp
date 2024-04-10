// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<vector<int>> prefs;
  string p = "abc";
  do {
    vector<int> pref(n + 1);
    for (int i = 0; i < n; ++i) {
      pref[i + 1] = pref[i] + (s[i] != p[i % 3]);
    }
    prefs.push_back(pref); 
  } while (next_permutation(p.begin(), p.end()));
  
  while (m--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    int ans = (r - l + 1);
    for (auto& pref : prefs) {
      ans = min(ans, pref[r + 1] - pref[l]);
    }
    cout << ans << '\n';
  }
}