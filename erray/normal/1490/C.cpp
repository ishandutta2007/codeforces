// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--){
    long long n;
    cin >> n;
    auto cube = [](int x) {
      return 1LL * x * x * x;
    };

    set<long long> st;
    bool ok = false;
    for (int i = 1; cube(i) < n; ++i) {
      st.insert(cube(i));
      if (st.count(n - cube(i))) {
        ok = true;
      }
    }

    cout << (ok ? "YES" : "NO") << '\n';
  }
}