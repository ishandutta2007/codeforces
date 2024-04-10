// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#define here void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    array<int, 32> ct = {};
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      for (int j = 0; j < 32; ++j) {
        if ((a[i] >> j) & 1) {
          ++ct[j];
        }
      }
    }
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
      bool ok = true;
      for (int j = 0; j < 32; ++j) {
        ok &= ct[j] % i == 0;
      }
      if (ok) {
        ans.push_back(i);
      }
    }
    for (auto e : ans) {
      cout << e << ' ';
    }
    cout << '\n';
  }
}