// April 10, 2020
// https://codeforces.com/contest/1334/problem/D

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
    long long n, l, r;
    cin >> n >> l >> r;
    long long tot = 0;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
      int add = 2 * (n - i);
      if (l <= tot + add && r > tot) {
        for (int j = i + 1; j <= n; j++) {
          tot++;
          if (l <= tot && tot <= r) {
            ans.push_back(i);
          }
          tot++;
          if (l <= tot && tot <= r) {
            ans.push_back(j);
          }
        }
      } else {
        tot += add;
      }
    }
    tot++;
    if (tot <= r) {
      ans.push_back(1);
    }
    for (int i = 0; i < (int) ans.size(); i++) {
      if (i > 0) {
        cout << ' ';
      }
      cout << ans[i];
    }
    cout << '\n';
  }


  return 0;
}