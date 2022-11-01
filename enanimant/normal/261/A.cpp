// May 12, 2020
// https://codeforces.com/contest/261/problem/A

/*
*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif
  
  
  int m;
  cin >> m;
  vector<int> d(m);
  for (int i = 0; i < m; i++) {
    cin >> d[i];
  }
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.rbegin(), a.rend());
  int mn = *min_element(d.begin(), d.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (i % (mn + 2) != mn && i % (mn + 2) != mn + 1) {
      ans += a[i];
    }
  }
  cout << ans << '\n';
  
  
  return 0;
}