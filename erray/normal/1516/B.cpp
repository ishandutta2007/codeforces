// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
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

    map<int, int> beg;
    int tot = 0;
    int zero = -1;
    for (int i = 0; i < n; ++i) {
      tot ^= a[i];
      if (tot == 0) {
        zero = i;
      }
      if (beg.count(tot) == 0) {
        beg[tot] = i;
      }
    }
    cout << (beg[tot] <= zero ? "YES" : "NO") << '\n';
  }
}