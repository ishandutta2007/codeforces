#include <bits/stdc++.h>

using namespace std;
using BS = bitset<2048>;
const int kMod = 1e9 + 7;

int main() {
  int m, n, r; cin >> n >> m >> r;
  vector<int> x(n), y(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i] >> b[i];
  }

  vector<BS> forbid(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int dx = x[i] - x[j], dy = y[i] - y[j];
      int d = max(abs(dx), abs(dy));
      if (d <= r) forbid[i][j] = true;
    }
  }
  
  /*
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      cerr << (forbid[i][j] ? '1' : '0');
    cerr << endl;
  }
  */

  vector<vector<int>> C(n + 1, vector<int>(n + 1, 0));
  for (int i = 0; i <= n; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
      if (C[i][j] >= kMod) 
        C[i][j] -= kMod;
    }
  }

  int total = 0;
  vector<int> coefs(n);
  for (int i = 0; i < n; ++i) {
    int cnt = forbid[i].count();
    int coef = (C[n][m] + kMod - C[n - cnt][m]) % kMod;
    coefs[i] = coef;
    // cerr << i << ": " << cnt << " " << coef << endl;
    total += 1LL * b[i] * b[i] % kMod * coef % kMod;
    if (total >= kMod) total -= kMod;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int cnt = (forbid[i] | forbid[j]).count();
      int coef = (C[n][m] - C[n - cnt][m] + kMod) % kMod;
      coef = (coefs[i] + coefs[j] - coef) % kMod;
      if (coef < 0) coef += kMod;
      // cerr << i << " " << j << ": " << cnt << " " << coef << endl;
      total += 2LL * b[i] * b[j] % kMod * coef % kMod;
      if (total >= kMod) total -= kMod;
    }
  }
  cout << total << endl;

  return 0;
}