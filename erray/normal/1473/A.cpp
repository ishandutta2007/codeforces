// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    } 
    sort(a.begin(), a.end());
    cout << (a[n - 1] <= d || (a[0] + a[1] <= d) ? "YES" : "NO") << '\n';
  }
}