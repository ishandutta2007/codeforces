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
      --a[i];
    }

    vector<int> u(n), freq(n);
    ++u[a[0]];
    ++u[a.back()];
    int ct = 0;
    for (int i = 0; i < n - 1; ++i) {
      if (a[i] == a[i + 1]) {
        u[a[i]] += 2;
        ++ct;
      }
      ++freq[a[i]];
    }
    ++freq[a.back()];
    if (*max_element(freq.begin(), freq.end()) > (n + 1) / 2) {
      cout << -1 << '\n';
      continue;  
    }
    
    int mx = *max_element(u.begin(), u.end()) - 2;
    cout << ct + max(0, mx - ct) << '\n';   
  }
}