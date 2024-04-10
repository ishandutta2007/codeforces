// June 25, 2020
// https://codeforces.com/contest/1373/problem/C

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
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<int> first(n + 1, -1);
    int x = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '+') {
        x++;
      } else {
        x--;
        if (x < 0 && first[-x] == -1) {
          first[-x] = i;
        }
      }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += first[i] + 1;
    }
    cout << ans + n << '\n';
  }
  
  
  return 0;
}