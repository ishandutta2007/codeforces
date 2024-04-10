#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int N = 500 + 7;
int n, cnt[N], a[N][N], need;

void dfs(int r, int c, int col) {
  if (!need) {
    return;
  }
  need--;
  a[r][c] = col;
  if (a[r][c - 1] == -1) {
    dfs(r, c - 1, col);
  }
  if (a[r + 1][c] == -1) {
    dfs(r + 1, c, col);
  }
}

void test() {
  for (int i = 0; i <= n + 1; i++) for (int j = 0; j <= n + 1; j++) a[i][j] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      a[i][j] = -1;
    }
  }
  /**cout << "now = ";
  for (int i = 1; i <= n; i++) {
    cout << cnt[i] << " ";
  }
  cout << "\n";**/
  for (int i = 1; i <= n; i++) {
    need = cnt[i];
    dfs(i, i, cnt[i]);
    assert(need == 0);
  }
 /// cout << "ok : " << n << "\n";

 /// return;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cout << a[i][j] << " ";
    }
    cout << "\n";
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
   // freopen ("input", "r", stdin);
/**

  for (n = 1; n <= 10; n++) {
   /// cout << " = " << n << "\n";
    for (int i = 1; i <= n; i++) {
      cnt[i] = i;
    }
    test();
    while (next_permutation(cnt + 1, cnt + n + 1)) {
      test();
    }
  }**/

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> cnt[i];
  }
  test();
  return 0;
}