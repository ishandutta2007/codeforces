// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    auto Ask = [&](int t, int i, int j) {
      cout << "? " << t << ' ' << i + 1 << ' ' << j + 1 << ' ' << (t - 1 ? 1 : n - 1) << endl;
      int ret;
      cin >> ret;
      --ret;
      return ret;
    };

    vector<int> res(n, -1);
    for (int i = 0; i < n - 1; i += 2) {
      res[i] = Ask(2, i, i + 1);
    }

    int p = 0;
    while (p < n && res[p] != 0) {
      ++p;
    }

    if (p == n) {
      for (int i = 1; i < n; ++i) {
        if (n % 2 == 1 && i == n - 1) {
          if (Ask(2, i, 0) == 0) {
            p = i;
          }
        } else if (res[i - 1] == 1) {
          if (Ask(2, i, 0) == 0) {
            p = i;
          }
        }
      }  
    }

    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
      if (i != p) {
        ans[i] = Ask(1, p, i);
      }
    }
    
    cout << "! ";
    for (int i = 0; i < n; ++i) {
      cout << ans[i] + 1 << ' ';
    }
    cout << endl;
  }
}