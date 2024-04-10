// August 25, 2019
// https://codeforces.com/contest/1208/problem/B

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = n;
  for (int i = 0; i <= n; i++) {
    // leave i nums on left
    set<int> s;
    bool rep = false;
    for (int j = 0; j < i; j++) {
      if (s.count(a[j])) {
        rep = true;
      }
      s.insert(a[j]);
    }
    if (rep) {
      break;
    }
    for (int j = n - 1; j > i; j--) {
      if (!s.count(a[j])) {
        s.insert(a[j]);
      } else {
        break;
      }
    }
    ans = min(ans, n - (int) s.size());
  }
  cout << ans << '\n';


  return 0;
}