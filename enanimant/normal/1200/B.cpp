// August 11, 2019
// https://codeforces.com/contest/1200/problem/A

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
      cin >> h[i];
    }
    int bag = m;
    bool win = true;
    for (int i = 0; i < n - 1; i++) {
      int r = h[i] - (h[i + 1] - k);
      if (r > h[i]) {
        r = h[i];
      }
      bag += r;
      if (bag < 0) {
        win = false;
      }
    }
    cout << (win ? "YES" : "NO") << '\n';
  }


  return 0;
}