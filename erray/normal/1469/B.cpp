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

    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
      cin >> b[i];
    }

    for (int i = 1; i < n; ++i) {
      a[i] = a[i - 1] + a[i];  
    }

    for (int i = 1; i < m; ++i) {
      b[i] = b[i - 1] + b[i];  
    }

    cout << max(*max_element(a.begin(), a.end()), 0) + max(0, *max_element(b.begin(), b.end())) << '\n';
  }
}