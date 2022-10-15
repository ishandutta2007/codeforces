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
    vector<int> k(n), c(m);
    for (int i = 0; i < n; ++i) {
      cin >> k[i];
      --k[i];
    }

    for (int i = 0; i < m; ++i) {
      cin >> c[i];
    }

    sort(k.rbegin(), k.rend());
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += c[min(k[i], i)];  
    }

    cout << ans << '\n';
  }
}