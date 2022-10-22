#include <bits/stdc++.h>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

int main() {
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  n = 4 * n + 1;
  vector<int> x(n), y(n); REP(i, n) cin >> x[i] >> y[i];
  REP(c, 51) REP(r, 51) FOR(len, 1, 51) {
    int ansx = -1, ansy = -1;
    REP(i, n) {
      bool exist = false;
      if (x[i] == c || x[i] == c + len) {
        if (r <= y[i] && y[i] <= r + len) exist = true;
      }
      if (y[i] == r || y[i] == r + len) {
        if (c <= x[i] && x[i] <= c + len) exist = true;
      }
      if (!exist) {
        if (ansx >= 0) {
          ansx = -2;
        } else if (ansx == -1) {
          ansx = x[i];
          ansy = y[i];
        }
      }
    }
    if (ansx >= 0) {
      cout << ansx << ' ' << ansy << '\n';
      return 0;
    }
  }
  assert(false);
}