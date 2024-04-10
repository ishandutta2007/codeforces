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
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    bool ok = true;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += a[i];
      if (sum < i) {
        ok = false;
      }

      sum -= i;
    }

    cout << (ok ? "YES" : "NO") << '\n';
  }
}