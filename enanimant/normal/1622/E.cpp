/*
 * author:  ADMathNoob
 * created: 12/31/21 17:29:04
 * problem: https://codeforces.com/contest/1622/problem/E
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        char c;
        cin >> c;
        a[i][j] = c - '0';
      }
    }
    int best = 0;
    vector<int> order(m);
    iota(order.begin(), order.end(), 0);
    for (int mm = 0; mm < (1 << n); mm++) {
      int total = 0;
      vector<int> coeff(n);
      for (int i = 0; i < n; i++) {
        coeff[i] = (((mm >> i) & 1) ? +1 : -1);
        total += -coeff[i] * x[i];
      }
      vector<int> w(m);
      vector<int> cnt_w(2 * n + 1);
      for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
          w[j] += coeff[i] * a[i][j];
        }
        cnt_w[w[j] + n] += 1;
      }
      int k = 1;
      for (int ww = -n; ww <= n; ww++) {
        for (int it = 0; it < cnt_w[ww + n]; it++) {
          total += ww * k;
          k += 1;
        }
      }
      if (total > best) {
        best = total;
        sort(order.begin(), order.end(), [&](int i, int j) {
          return w[i] < w[j];
        });
      }
    }
    vector<int> p(m);
    for (int z = 0; z < m; z++) {
      p[order[z]] = z + 1;
    }
    for (int j = 0; j < m; j++) {
      if (j > 0) cout << ' ';
      cout << p[j];
    }
    cout << '\n';
  }
  return 0;
}