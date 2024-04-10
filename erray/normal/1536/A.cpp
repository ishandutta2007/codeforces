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

    set<int> in(a.begin(), a.end());
    for (int i = 0; i < int(a.size()) && int(a.size()) <= 300; ++i) {
      for (int j = 0; j < int(a.size()) && int(a.size()) <= 300; ++j) {
        if (i == j) {
          continue;
        }  
        int add = abs(a[i] - a[j]);
        if (in.count(add) == 0) {
          in.insert(add);
          a.push_back(add);
        }
      }
    }
    if (int(a.size()) > 300) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";    
    cout << int(a.size()) << '\n';
    for (auto e : a) {
      cout << e << ' ';
    }
    cout << '\n';
  }
}