// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(m);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
    }

    for (int i = 0; i < n; ++i) {
      cin >> b[i];
      --b[i];
    }

    for (int i = 0; i < m; ++i) {
      cin >> c[i];
      --c[i];
    }

    reverse(c.begin(), c.end());
    if (count(b.begin(), b.end(), c[0]) == 0) {
      cout << "NO\n";
      continue;
    }

    vector<vector<int>> ct(n);
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i]) {
        ct[b[i]].push_back(i);
      }
    }
    
    int trash = -1;
    if (ct[c[0]].empty()) {
      for (int i = 0; i < n; ++i) {
        if (b[i] == c[0]) {
          trash = i;
        }
      }
    } else {
      trash = ct[c[0]].back();
    }

    assert(trash != -1);
    vector<int> ans(m);
    int cur = 0;
    for (auto e : c) {
      if (ct[e].empty()) {
        ans[cur] = trash; 
      } else {
        ans[cur] = ct[e].back();
        ct[e].pop_back();
      }
      ++cur;
    }

    bool ok = true;
    for (auto e : ct) {
      ok &= (e.empty());
    }
    
    if (!ok) {
      cout << "NO\n";
      continue;
    }

    cout << "YES\n";
    reverse(ans.begin(), ans.end());
    for (auto e : ans) {
      cout << e + 1 << ' ';
    }
  }
}