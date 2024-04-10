#include <iostream>
#include <vector>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vvi submasks(1 << m);
  for (int mask = 0; mask < (1 << m); mask++)
    for (int submask = 0; submask < (1 << m); submask++)
      if ((mask | submask) == (1 << m) - 1)
        submasks[mask].push_back(submask);
  vvi mat(n, vi(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> mat[i][j];
  int L = 0, R = 1e9;
  while (L != R) {
    int M = (L + R + 1) / 2;
    vector <bool> used(1 << m);
    for (int i = 0; i < n; i++) {
      int mask = 0;
      for (int j = 0; j < m; j++)
        if (mat[i][j] >= M)
          mask |= (1 << j);
      used[mask] = true;
    }
    bool flag = false;
    for (int mask = 0; mask < (1 << m); mask++)
      for (int submask : submasks[mask])
        if (used[mask] && used[submask]) {
          flag = true;
          break;
        }
    if (flag)
      L = M;
    else
      R = M - 1;
  }
  vvi used(1 << m);
  for (int i = 0; i < n; i++) {
    int mask = 0;
    for (int j = 0; j < m; j++)
      if (mat[i][j] >= L)
        mask |= (1 << j);
    used[mask].push_back(i + 1);
  }
  for (int mask = 0; mask < (1 << m); mask++)
    for (int submask : submasks[mask])
      if (!used[mask].empty() && !used[submask].empty()) {
        cout << used[mask][0] << ' ' << used[submask][0] << '\n';
        return 0;
      }
  return 0;
}