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

  if (set<int>(a.begin(), a.end()).size() == (int) a.size()) {
    cout << 0 << '\n';
    return 0;
  }

  map<int, int> ct;
  int more = 0;
  for (auto e : a) {
    ++ct[e];
    if (ct[e] == 2) {
      ++more;
    }
  }


  int ans = INT_MAX;
  for (int i = 0; i < n; ++i) {
    int left = more;
    for (int j = i; j >= 0; --j) {
      --ct[a[j]];
      if (ct[a[j]] == 1) {
        --left;
      }

      if (left == 0) {
        ans = min(ans, i - j + 1);
      }
    }

    for (int j = 0; j <= i; ++j) { 
      ++ct[a[j]];
    }
  }

  cout << ans << '\n';
}