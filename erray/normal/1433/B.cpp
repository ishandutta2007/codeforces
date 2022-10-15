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
    vector<int> pos;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] == 1) {
        if (!pos.empty()) {
          ans += i - pos.back() - 1;
        }
        pos.push_back(i);
      }
    }
    cout << ans << '\n';
  }
}