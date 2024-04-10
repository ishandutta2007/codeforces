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
    vector<int> x(n + m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int w;
        cin >> w;
        x[i + j] ^= w;
      }
    }
    cout << (accumulate(x.begin(), x.end(), 0LL) ? "Ashish" : "Jeel") << '\n';
  }
}