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
    string s, t;
    cin >> n >> k >> s >> t;
    vector<int> ct(26), ctT(26);
    for (int i = 0; i < n; ++i) {
      ct[s[i] - 'a']++;
      ctT[t[i] - 'a']++;
    }
    bool ok = true;
    int ex = 0;
    for (int i = 0; i < 26; ++i) {
      if (ct[i] == ctT[i]) {
        continue;
      }

      if (ctT[i] > ct[i]) {
        int f = ctT[i] - ct[i];
        ok &= (f % k == 0 && f <= ex);
        ex -= f;
      } else {
        int f = ct[i] - ctT[i];
        ok &= (f % k == 0);
        ex += f; 
      }
    }

    cout << (ok && ex == 0 ? "Yes" : "No") << '\n';
  }
}