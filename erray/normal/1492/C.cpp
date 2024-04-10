// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  vector<int> suf(m + 1, n);
  vector<int> pref(m + 1, -1);
  for (int i = 1; i <= m; ++i) {
    pref[i] = pref[i - 1] + 1;
    suf[i] = suf[i - 1] - 1;
    char sc = t[m - i];
    char pc = t[i - 1];    
    while (pref[i] < n && s[pref[i]] != pc) {
      ++pref[i];
    }

    while (suf[i] >= 0 && s[suf[i]] != sc) {
      --suf[i];
    }

  }

  int ans = -1;
  for (int i = 1; i < m; ++i) {
    ans = max(ans, suf[i] - pref[m - i]);
  }

  cout << ans << '\n';
}