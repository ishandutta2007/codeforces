// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    a.push_back(1);
    int pos = 0;
    if (a[0] == 1) {
      pos = -1;
      cout << n + 1 << ' ';
    } else {
      while (a[pos] >= a[pos + 1]) {
        ++pos;
      }
    }

    for (int i = 0; i < n; ++i) {
      cout << i + 1 << ' ';
      if (i == pos) {
        cout << n + 1 << ' ';
      }  
    }
    cout << '\n';
  }
}