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
    sort(a.begin(), a.end());
    vector<int> ct(100 + 1);
    vector<int> lst;
    for (auto e : a) {
      if (++ct[e] == 1) {
        cout << e << ' ';
      } else {
        lst.push_back(e);
      }
    }

    for (auto e : lst) {
      cout << e << ' ';
    }
  }
}