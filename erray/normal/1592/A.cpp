// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, H;
    cin >> n >> H;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    int sum = a[0] + a[1];
    cout << (H / sum) * 2 + !!(H % sum) + ((H % sum) > a[0]) << '\n';
  }
}