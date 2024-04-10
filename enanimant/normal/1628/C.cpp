/*
 * author:  ADMathNoob
 * created: 01/22/22 09:35:15
 * problem: https://codeforces.com/contest/1628/problem/C
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

#ifdef _DEBUG
#include "../algorithms/debug/debug.h"
#else
#define debug(...) 42
#endif

const vector<int> di = {1, 0, -1, 0};
const vector<int> dj = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;

    auto InRange = [&](int i, int j) {
      return (0 <= i && i < n && 0 <= j && j < n);
    };
    
    auto Ok = [&](const vector<vector<int>>& a, const vector<vector<int>>& x) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          int y = 0;
          for (int d = 0; d < 4; d++) {
            int ii = i + di[d];
            int jj = j + dj[d];
            if (InRange(ii, jj)) {
              y ^= x[ii][jj];
            }
          }
          if (y != a[i][j]) {
            return false;
            debug(i, j, a[i][j], y);
          }
        }
      }
      return true;
    };
    
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
      }
    }
    vector<vector<int>> res(n, vector<int>(n));
    for (int h = 0; h < 31; h++) {
      vector<vector<int>> b(n, vector<int>(n));
      vector<vector<int>> x(n, vector<int>(n));
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          b[i][j] = ((a[i][j] >> h) & 1);
        }
      }
      bool found = [&] {
        for (x[0][0] = 0; x[0][0] < 2; x[0][0]++) {
          for (x[0][1] = 0; x[0][1] < 2; x[0][1]++) {
            for (int i = 1; i < n; i++) {
              for (int j = 0; j < n; j++) {
                x[i][j] = b[i - 1][j];
                if (j - 1 >= 0) {
                  x[i][j] ^= x[i - 1][j - 1];
                }
                if (j + 1 < n) {
                  x[i][j] ^= x[i - 1][j + 1];
                }
                if (i - 2 >= 0) {
                  x[i][j] ^= x[i - 2][j];
                }
              }
            }
            if (Ok(b, x)) {
              return true;
            }
          }
        }
        return false;
      }();
      assert(found);
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          res[i][j] |= (x[i][j] << h);
        }
      }
    }
    // for (int rot = 0; rot < 2; rot++) {
    //   for (int i = 0; i < n - 1; i++) {
    //     res[i][i] = 0;
    //   }
    //   for (int t = 0; t < 2; t++) {
    //     for (int d = 2; d < n; d += 2) {
    //       assert(0 <= d - 2);
    //       res[0][d] = a[0][d - 1] ^ res[0][d - 2] ^ res[1][d - 1];
    //       for (int j = d + 1; j < n; j++) {
    //         int i = j - d;
    //         assert(0 <= j - 2);
    //         res[i][j] = a[i][j - 1] ^ res[i - 1][j - 1] ^ res[i][j - 2] ^ res[i + 1][j - 1];
    //       }
    //     }
    //     debug(res);
    //     for (int i = 0; i < n; i++) {
    //       for (int j = 0; j < n; j++) {
    //         if (i < j) {
    //           swap(a[i][j], a[j][i]);
    //           swap(res[i][j], res[j][i]);
    //         }
    //       }
    //     }
    //   }
    //   res[n - 1][n - 1] = a[n - 1][n - 2] ^ res[n - 2][n - 2];
    //   if (n >= 3) {
    //     res[n - 1][n - 1] ^= res[n - 1][n - 3];
    //   }
    //   {
    //     int y = res[n - 1][n - 1] ^ res[n - 2][n - 2];
    //     if (n >= 3) {
    //       y ^= res[n - 3][n - 1];
    //     }
    //     assert(y == a[n - 2][n - 1]);
    //   }
    //   for (int i = 0; i < n; i++) {
    //     for (int j = 0; 2 * j < n; j++) {
    //       swap(a[i][j], a[i][n - 1 - j]);
    //       swap(res[i][j], res[i][n - 1 - j]);
    //     }
    //   }
    // }
    debug(res);
    assert(Ok(a, res));
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ans ^= res[i][j];
      }
    }
    cout << ans << '\n';
  }
  return 0;
}