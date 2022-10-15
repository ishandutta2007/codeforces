// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
      cin >> d[i];
    }
    sort(d.begin(), d.end());
    long long sum = 0;
    long long ans = d.back();
    for (int i = 0; i < n; ++i) {
      ans -= 1LL * d[i] * i - sum;
      sum += d[i];
    }
    cout << ans << '\n';
  }  
}