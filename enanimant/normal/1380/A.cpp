// July 12, 2020
// https://codeforces.com/contest/1380/problem/A

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
    vector<int> a(n), pos(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
      pos[a[i]] = i;
    }
    int l = 0, r = n - 1;
    bool ok = false;
    for (int i = n - 1; i >= 0; i--) {
      if (pos[i] == l) {
        l++;
      } else if (pos[i] == r) {
        r--;
      } else {
        cout << "YES\n";
        cout << l + 1 << ' ' << pos[i] + 1 << ' ' << r + 1 << '\n';
        ok = true;
        break;
      }
    }
    if (!ok) {
      cout << "NO\n";
    }
  }
  
  
  return 0;
}