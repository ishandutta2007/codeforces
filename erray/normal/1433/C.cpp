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
    int mx = *max_element(a.begin(), a.end());
    int ans = -2;
    for (int i = 0; i < n; ++i) {
      int next = mx, prev = mx;
      if (i > 0) {
        prev = a[i - 1];
      }
      if (i < n - 1) {
        next = a[i + 1];
      }
      if (a[i] == mx && (prev != mx || next != mx)) {
        ans = i;
      }
    }
    cout << ans + 1 << '\n';
  }
}