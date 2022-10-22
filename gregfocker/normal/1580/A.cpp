#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
///#define int ll

const int N = 400 + 7;
int tt, n, m, a[N][N], nd[N], p1[N], p2[N], pe[N], sum[N], ff[N], ss[N];


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);

  cin >> tt;
  while (tt--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      string s;
      cin >> s;
      for (int j = 1; j <= m; j++) {
        a[i][j] = s[j - 1] - '0';
      }
    }
    /**

    a >= 5 rows
    b >= 4 cols
    1 = obsidian

    **/
    int sol = (int) 1e9;
    for (int lo = 1; lo <= n; lo++) {
      for (int i = 1; i <= m; i++) {
        nd[i] = 0;
        p1[i] = p1[i - 1] + (a[lo][i] == 0);
        pe[i] = 0;
      }
      for (int hi = lo; hi <= n; hi++) {
        for (int i = 1; i <= m; i++) {
          p2[i] = p2[i - 1] + (a[hi][i] == 0);
        }
        for (int i = 1; i <= m; i++) {
          ff[i] = nd[i] - p1[i] - p2[i] - sum[i];
          ss[i]  = nd[i] + p1[i - 1] + p2[i - 1] + sum[i - 1];
        }
        if (hi - lo + 1 >= 5) {
          int maxx = (int) 1e9;
          for (int r = 1; r <= m; r++) {
            if (r - 3 >= 1) {
              maxx = min(maxx, ff[r - 3]);
              sol = min(sol, maxx + ss[r]);
            }
          }
        }
        if (hi > lo) {
          for (int i = 1; i <= m; i++) {
            nd[i] += (a[hi][i] == 0);
            pe[i] += a[hi][i];
            sum[i] = sum[i - 1] + pe[i];
          }
        }

      }
    }
    cout << sol << "\n";

  }


  return 0;
}