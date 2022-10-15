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
    vector<int> a, b;
    for (int i = 0; i < n * 2; ++i) {
      int x, y;
      cin >> x >> y;
      if (x == 0) {
        b.push_back(abs(y));
      } else {
        a.push_back(abs(x));
      }
    }
    long double ans = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n; ++i) {
      ans += sqrt(1LL * a[i] * a[i] + 1LL * b[i] * b[i]); 
    }
    cout << fixed << setprecision(9) << ans << '\n';
  }
}