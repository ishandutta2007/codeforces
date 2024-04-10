// July 11, 2020
// https://codeforces.com/contest/1372/problem/C

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
    vector<int> a(n);
    int x = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
      if (a[i] == i) {
        x++;
      }
    }
    if (x == n) {
      cout << "0\n";
      continue;
    }
    int l = 0, r = n - 1;
    while (l < n && a[l] == l) {
      l++;
    }
    while (r >= l && a[r] == r) {
      r--;
    }
    x = 0;
    for (int i = l; i <= r; i++) {
      if (a[i] == i) {
        x++;
      }
    }
    if (x == 0) {
      cout << "1\n";
      continue;
    }
    cout << "2\n";
  }
  
  
  return 0;
}