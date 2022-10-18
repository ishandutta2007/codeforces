#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>
#include <bitset>

using namespace std;

int n;

bool mat[64][502][502], inv[64][502][502], tmp[502][502], my[502][502];

void mult(bool res[502][502], bool a[502][502], bool b[502][502]) {
  bitset<502> rows[502], cols[502];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      rows[i].set(j, a[i][j]);
      cols[j].set(i, b[i][j]);
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      res[i][j] = (rows[i] & cols[j]).count() > 0;
    }
  }
}

bool check(bool mat[502][502]) {
  for (int i = 0; i < n; ++i)
    if (mat[0][i]) return true;
  return false;
}

int main() {
  ios::sync_with_stdio(false);

  int m;
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int a, b, t;
    cin >> a >> b >> t;
    --a; --b;
    if (t == 0) mat[0][a][b] = true;
    else inv[0][a][b] = true;
  }

  for (int it = 1; it < 62; ++it) {
    mult(mat[it], mat[it - 1], inv[it - 1]);
    mult(inv[it], inv[it - 1], mat[it - 1]);
  }

  if (check(mat[60])) {
    cout << -1 << endl;
    return 0;
  }

  long long ans = 0;

  for (int it = 61; it >= 0; --it) {
    if (check(mat[it])) {
      ans = 1LL << it;

      memcpy(my, mat[it], sizeof(my));

      bool what = false;
      for (int i = it - 1; i >= 0; --i) {
        if (!what)
          mult(tmp, my, inv[i]);
        else
          mult(tmp, my, mat[i]);

        if (check(tmp)) {
          memcpy(my, tmp, sizeof(my));
          ans += 1LL << i;
          what = !what;
        }
      }

      break;
    }
  }

  if (ans >= 1000000000000000000LL) ans = -1;

  cout << ans << endl;

  return 0;
}