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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int left = int(min_element(a.begin(), a.end()) - a.begin());
    int right = int(max_element(a.begin(), a.end()) - a.begin());
    if (left > right) {
      swap(left, right);
    }
    cout << min({n - (right - left - 1), right + 1, n - left}) << '\n';
  }
}