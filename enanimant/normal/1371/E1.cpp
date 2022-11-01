// July 1, 2020
// https://codeforces.com/contest/1371/problem/E1

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
  
  
  int n, p;
  cin >> n >> p;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int M = *max_element(a.begin(), a.end());
  vector<int> ans;
  for (int x = M - n + 1; x < M; x++) {
    bool ok = true;
    for (int i = 0; i < n; i++) {
      b[i] = max(a[i] - x, 0);
      int ways = i + 1 - b[i];
      if (ways % p == 0) {
        ok = false;
      }
    }
    if (ok) {
      ans.push_back(x);
    }
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < (int) ans.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << ans[i];
  }
  cout << '\n';
  
  
  return 0;
}