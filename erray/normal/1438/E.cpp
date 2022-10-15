// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  set<pair<int, int>> st;
  auto solve = [&](bool push = false) {
    for (int i = 0; i < n - 2; ++i) {
      int big = 1 << (32 - __builtin_clz(a[i]));
      long long sum = a[i + 1];
      for (int j = i + 2; j < n && sum < big; ++j) {
        if (sum == (a[i] ^ a[j])) {
          if (push) {
            st.emplace(i, j);
          } else {
            st.emplace(n - j - 1, n - i - 1);
          }
        }
        sum += a[j];            
      }
    }
  };

  solve();
  reverse(a.begin(), a.end());
  solve(true);
  cout << (int) st.size() << '\n';
}