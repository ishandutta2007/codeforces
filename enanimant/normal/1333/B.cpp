// April 8, 2020
// https://codeforces.com/contest/1333/problem/B

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
      cin >> a[i];
    }
    bool ok = true;
    vector<bool> seen(3, false);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      if (a[i] < b[i]) {
        ok &= seen[2];
      } else if (a[i] > b[i]) {
        ok &= seen[0];
      }
      seen[a[i] + 1] = true;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }


  return 0;
}