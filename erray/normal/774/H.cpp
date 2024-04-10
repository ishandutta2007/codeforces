// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  string ans;
  char now = 'a';
  for (int j = n - 1; j >= 0; --j) {
    //cerr << a[j] << ' ';
    if (a[j] > 0) {
      for (int i = 0; i < a[j]; ++i) {
        ans += string(j + 1, now);
        if (now == 'z') {
          now = 'a' - 1;
        }
        ++now;
      }
      for (int i = j - 1; i >= 0; --i) {
        a[i] -= a[j] * (j - i + 1);   
      }
    }
  }
  cout << ans << '\n';
}