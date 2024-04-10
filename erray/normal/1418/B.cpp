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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
      cin >> l[i];
    }

    vector<int> ord;
    for (int i = 0; i < n; ++i) {
      if (!l[i]) {
        ord.push_back(a[i]);
      }
    }
    sort(ord.begin(), ord.end());
    for (int i = 0; i < n; ++i) {
      if (l[i]) {
        cout << a[i];
      } else {
        cout << ord.back();
        ord.pop_back();
      }
      cout << " \n"[i == n - 1];
    }
  }
}