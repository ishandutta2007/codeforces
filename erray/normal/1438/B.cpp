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
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }
    set<int> a(b.begin(), b.end());
    cout << ((int) a.size() == n ? "NO" : "YES") << '\n';
  }
}