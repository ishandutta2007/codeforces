// March 23, 2020
// https://codeforces.com/contest/1327/problem/D

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
    int n;
    cin >> n;
    vector<int> p(n), c(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      p[i]--;
    }
    for (int i = 0; i < n; i++) {
      cin >> c[i];
      c[i]--;
    }
    int ans = n;
    vector<bool> mark(n);
    for (int i = 0; i < n; i++) {
      if (mark[i]) {
        continue;
      }
      vector<int> cycle;
      int x = i;
      do {
        x = p[x];
        cerr << x << ' ';
        mark[x] = true;
        cycle.push_back(x);
      } while (x != i);
      cerr << '\n';
      int m = (int) cycle.size();
      for (int d = 1; d <= m; d++) {
        if (m % d == 0) {
          for (int j = 0; j < d; j++) {
            bool works = true;
            int cc = c[cycle[j]];
            for (int k = j; k < m; k += d) {
              if (c[cycle[k]] != cc) {
                works = false;
                break;
              }
              cc = c[cycle[k]];
            }
            if (works) {
              ans = min(ans, d);
              break;
            }
          }
        }
      }
    }
    cout << ans << '\n';
  }


  return 0;
}