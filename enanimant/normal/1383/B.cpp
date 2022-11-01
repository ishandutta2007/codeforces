// July 24, 2020
// https://codeforces.com/contest/1383/problem/B

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
      x ^= a[i];
    }
    if (x == 0) {
      cout << "DRAW\n";
      continue;
    }
    for (int j = 30; j >= 0; j--) {
      if (x & (1 << j)) {
        vector<int> cnt(2);
        for (int i = 0; i < n; i++) {
          if (a[i] & (1 << j)) {
            cnt[1]++;
          } else {
            cnt[0]++;
          }
        }
        assert(cnt[1] % 2 == 1);
        if (cnt[0] % 2 == 1 || cnt[1] % 4 == 1) {
          cout << "WIN\n";
        } else {
          cout << "LOSE\n";
        }
        // cout << (cnt[1] % 4 == 1 ? "WIN" : "LOSE") << '\n';
        break;
      }
    }
  }
  
  
  return 0;
}