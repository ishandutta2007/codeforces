// June 25, 2020
// https://codeforces.com/contest/1373/problem/E

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
    int n, k;
    cin >> n >> k;
    k++;
    long long ans = 1e18;
    for (int d = 0; d < 10; d++) {
      int m = n;
      for (int i = d; i < d + k; i++) {
        m -= i % 10;
      }
      int f = min(10 - d, k);
      for (int c = 0; c < 20; c++) {
        int num = m - (k - f) * (1 - 9 * c);
        if (num % k != 0) {
          continue;
        }
        int s = num / k;
        if (s < 9 * c) {
          continue;
        }
        vector<int> res(c, 9);
        s -= 9 * c;
        int nex = min(s, 8);
        res.push_back(nex);
        s -= nex;
        while (s > 0) {
          nex = min(s, 9);
          res.push_back(nex);
          s -= nex;
        }
        long long x = 0;
        for (int i = (int) res.size() - 1; i >= 0; i--) {
          x *= 10;
          x += res[i];
        }
        x = x * 10 + d;
        ans = min(ans, x);
      }
    }
    if (ans > 0.9e18) {
      ans = -1;
    }
    cout << ans << '\n';
  }
  
  
  return 0;
}