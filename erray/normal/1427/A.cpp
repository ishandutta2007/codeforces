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
    sort(a.rbegin(), a.rend());
    auto check = [&] {
      int sum = 0;
      for (int i = 0; i < n; ++i) {
        sum += a[i];  
        if (sum == 0) {
          return false;
        }
      }
      return true;
    };
    int ct = n;
    while (--ct && !check()) {
      rotate(a.begin(), a.begin() + 1, a.end());
    }
    if (!check()) {
      cout << "NO\n";
      continue;
    }

    cout << "YES\n";
    for (auto el : a) {
      cout << el << ' ';
    }
    cout << '\n';
  }
}