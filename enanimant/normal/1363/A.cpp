// May 31, 2020
// https://codeforces.com/contest/1363/problem/A

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
    int n, x;
    cin >> n >> x;
    vector<int> cnt(2, 0);
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      cnt[a % 2]++;
    }
    bool ok = false;
    for (int i = 0; i <= cnt[0]; i++) {
      ok |= (x - i <= cnt[1] && (x - i) % 2 == 1);
    }
    cout << (ok ? "yes" : "no") << '\n';
  }
  
  
  return 0;
}