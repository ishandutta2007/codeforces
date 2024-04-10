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
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int ans = 0;
    while (!is_sorted(a.begin(), a.end())) {
      int ind = -1;
      for (int i = n - 1; i >= 0; --i) {
        if (a[i] > x) {
          ind = i;
        }
      }
      if (ind == -1) {
        break;
      }

      swap(x, a[ind]);
      ++ans;
    }  
    cout << (is_sorted(a.begin(), a.end()) ? ans : -1) << '\n';
  }
}