// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    long long sum = accumulate(a.begin(), a.end(), 0LL);
    int ans = 0;
    if (max_element(a.begin(), a.end()) == min_element(a.begin(), a.end()) && a[0] == x) ans = 0;
    else {
      bool ex = false;
      for (auto el : a) ex |= (el == x);
      if (1LL * n * x == sum || ex) ans = 1;
      else ans = 2;
    }
    cout << ans << '\n';
  }
}