#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vii vector<vi>
#define rep(i, n) for (int i = 0; i < n; i++)
#define pii pair<int, int>

int main () {
  int n, m;
  cin >> n >> m;
  vii a(2, vi(n));
  vii b(2, vi(n));
  rep (i, n) {
    cin >> b[0][i];
  }
  rep (i, 2) {
    rep (j, n) {
      cin >> a[i][j];
    }
  }
  rep (i, n) {
    cin >> b[1][i];
  }
  vector<pair<int, pii> > ans;
  int cnt = 0;
  rep (i, 2) {
    rep (j, n) {
      if (a[i][j] > 0 && a[i][j] == b[i][j]) {
        if (i == 0) {
          ans.push_back(make_pair(a[i][j], pii(1, j + 1)));
        }
        else {
          ans.push_back(make_pair(a[i][j], pii(4, j + 1)));
        }
        a[i][j] = 0;
        cnt++;
      }
    }
  }
  if (m == 2*n && ans.size() == 0) {
    cout << -1 << endl;
    return 0;
  }
  int nowi = -1, nowj = -1;
  rep (i, 2) {
    rep (j, n) {
      if (a[i][j] == 0) {
        nowi = i; nowj = j;
      }
    }
  }
  while (cnt < m) {
    int nexi, nexj;
    if (nowi == 0) {
      if (nowj < n - 1) {
        nexi = nowi;
        nexj = nowj + 1;
      }
      else {
        nexi = 1; nexj = n - 1;
      }
    }
    else {
      if (nowj > 0) {
        nexi = nowi;
        nexj = nowj - 1;
      }
      else {
        nexi = 0; nexj = 0;
      }
    }
    if (a[nexi][nexj] > 0) {
      ans.push_back(make_pair(a[nexi][nexj], pii(nowi + 2, nowj + 1)));
      a[nowi][nowj] = a[nexi][nexj];
      a[nexi][nexj] = 0;
    }
    nowi = nexi; nowj = nexj;
    rep (i, 2) {
      rep (j, n) {
        if (a[i][j] > 0 && a[i][j] == b[i][j]) {
          if (i == 0) {
            ans.push_back(make_pair(a[i][j], pii(1, j + 1)));
          }
          else {
            ans.push_back(make_pair(a[i][j], pii(4, j + 1)));
          }
          a[i][j] = 0;
          cnt++;
        }
      }
    }
  }
  cout << ans.size() << endl;
  rep (i, ans.size()) {
    cout << ans[i].first << " " << ans[i].second.first << " " << ans[i].second.second << endl;
  }
  return 0;
}