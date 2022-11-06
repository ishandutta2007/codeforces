#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 5005;
int n, a[N], f[N], s[N][N];

void gu(int &x, int &y, int z) {
  if (!x)
    x = z, y = 1;
  else if (x == z)
    y++;
  else {
    y--;
    if (!y)
      x = 0;
  }
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i], s[i][a[i]]++;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      s[i][j] += s[i - 1][j];
  for (int i = 1; i <= n + 1; i++) {
    f[i] = -2 * n;
    for (int j = i - 1, x = 0, y = 0; j >= 0; j -= 2) {
      if (x == 0 || s[i - 1][x] - s[j][x] <= (i - j - 1) / 2) {
        if (a[i] == a[j] || j == 0 || i == n + 1)
          f[i] = max(f[i], f[j] + 1);
      }
      gu(x, y, a[j]);
      if (j > 1)
        gu(x, y, a[j - 1]);
    }
  }
  cout << f[n + 1] - 1 << '\n';
  for (int i = 1; i <= n; i++)
    memset(s[i], 0, sizeof s[i]);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--)
    solve();
}