// May 6, 2020
// https://codeforces.com/contest/1344/problem/A

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
    vector<bool> taken(n, false);
    bool ok = true;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] %= n;
      if (a[i] < 0) {
        a[i] += n;
      }
      if (taken[(i + a[i]) % n]) {
        ok = false;
      }
      taken[(i + a[i]) % n] = true;
    }
    cout << (ok ? "yes" : "no") << '\n';
  }


  return 0;
}