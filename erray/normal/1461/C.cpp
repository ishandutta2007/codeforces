// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    
    int can = n;
    while (can > 0 && a[can - 1] == can) {
      --can;
    }

    long double ans = 0, cur = 1;
    while (m--) {
      int r;
      double p;
      cin >> r >> p;
      if (r >= can) {
        ans += cur * p;
        cur *= (1 - p);
      }  
    }
    cout << setprecision(7) << (can == 0 ? 1.0 : ans) << '\n';
  }
}