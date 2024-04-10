// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int lg = __lg(n) + 1;
    int lose = max(0, k - lg);
    k -= lose;
    string ans(lose, '0');
 
    vector<int> pref(n + 1);
    for (int i = 0; i < n; ++i) {
      pref[i + 1] = pref[i] + (s[i] - '0');
    }
    
    vector<int> bad(1 << k);
    for (int i = 0; i < n - k - lose + 1; ++i) {
      if (pref[i + lose] - pref[i] != lose) {
        continue;
      }

      int now = 0;
      for (int j = 0; j < k; ++j) {
        now += !(s[i + j + lose] - '0') << (k - j - 1);
      }
      bad[now] = true;
    }
 
    for (int i = 0; i < (1 << k); ++i) {
      if (!bad[i]) {
        for (int j = k - 1; j >= 0; --j) {
          ans += char('0' + ((i >> j) & 1));
        }
        break;
      }
    }
 
    if ((int) ans.size() != k + lose) {
      cout << "NO\n";
      continue;
    }
 
    cout << "YES\n" << ans << '\n';
  }
}