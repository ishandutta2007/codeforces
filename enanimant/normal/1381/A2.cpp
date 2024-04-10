// July 21, 2020
// https://codeforces.com/contest/1381/problem/A1

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
  
  
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      char c;
      cin >> c;
      a[i] = c - '0';
    }
    for (int i = 0; i < n; i++) {
      char c;
      cin >> c;
      b[i] = c - '0';
    }
    vector<int> ans;
    int x = 0;
    int l = 0, r = n - 1;
    for (int i = n - 1; i >= 0; i--) {
      a[l] ^= x;
      if (a[l] == b[i]) {
        ans.push_back(1);
        a[l] ^= 1;
      }
      ans.push_back(i + 1);
      x ^= 1;
      if (l <= r) {
        l++;
      } else {
        l--;
      }
      swap(l, r);
    }
    cout << ans.size();
    for (int x : ans) {
      cout << ' ' << x;
    }
    cout << '\n';
  }
  
  
  return 0;
}