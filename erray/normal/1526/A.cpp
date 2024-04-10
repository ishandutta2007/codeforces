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
    n *= 2;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int half = n / 2;
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 0) {
        cout << a[i / 2] << ' ';
      } else {
        cout << a[i / 2 + half] << ' ';
      }
    }
    cout << '\n';
  }
}