// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    string S;
    cin >> S;
    auto c = S;
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    int n = int(S.size());
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      a[i] = int(lower_bound(c.begin(), c.end(), S[i]) - c.begin());
    }

    int m = int(c.size());
    vector<int> ct(m);
    bool ok = true;
    for (int i = 0; i < n; ++i) {      
      ct[a[i]] += 1;
      if (i >= m) {
        ct[a[i - m]] -= 1;
      }
      ok &= ((*max_element(ct.begin(), ct.end())) <= 1);
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}