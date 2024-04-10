#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
///#define int ll

const int INF = (int) 1e9;


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  //freopen ("input", "r", stdin);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> valid(n, vector<int> (m, 0));
  vector<int> is(m + 1, 0);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      valid[i][j] = (s[j] == '.');
      if (i && j && !valid[i - 1][j] && !valid[i][j - 1]) {
        is[1 + j] = 1;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    is[i] += is[i - 1];
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (is[r] != is[l]) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  //for (int i = 0; i < n; )
  return 0;
}