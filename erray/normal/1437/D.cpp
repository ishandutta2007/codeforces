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
    int re = 1, st = 1, ans = 0;
    for (int i = 2; i < n; ++i) {
      if (a[i - 1] > a[i]) {
        --re;
        if (re == 0) {
          re = st;
          ++ans;
        }
      } else {
        ++st;
      }
    }
    cout << ans + 1 << '\n';
  }
}