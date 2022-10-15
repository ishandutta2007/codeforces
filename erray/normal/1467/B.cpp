// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    auto get = [&](int x) {
      return (x > 0 && x < n - 1 && ((a[x] > a[x - 1] && a[x] > a[x + 1]) || (a[x] < a[x - 1] && a[x] < a[x + 1])));
    };

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += get(i);
    }
    
    int best = 0;
    for (int i = 1; i < n - 1; ++i) {
      int start = a[i];
      auto New = [&](int x) {
        int res = 0;
        for (int j = -1; j < 2; ++j) {
          res -= get(i + j);
        }
        
        a[i] = x;
        for (int j = -1; j < 2; ++j) {
          res += get(i + j);
        }

        a[i] = start;
        return res;
      };

      best = min(best, New(a[i - 1]));
      best = min(best, New(a[i + 1]));
    }

    cout << ans + best << '\n';
  }
}