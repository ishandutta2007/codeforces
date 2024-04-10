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

    sort(a.begin(), a.end());
    int p = 0;
    while (p < n - 1 && a[p] == a[p + 1]) {
      ++p;
    }

    cout << n - 1 - p << '\n';
  }
}