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
    set<int> s;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      s.insert(x);
    }
    cout << ((int) s.size() == 1 ? n : 1) << '\n';
  }
}