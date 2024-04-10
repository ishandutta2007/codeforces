#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 5000005;
int n, s[N], f[N];
bool u[N];

void solve() {
  int m, mn = 1 << 30;
  cin >> m >> n;
  fill(f + 1, f + n + 1, n);
  while (m--) {
    int x;
    cin >> x;
    u[x] = 1, mn = min(mn, x);
  }
  for (int i = n; i > mn; i--)
    for (int j = 1; i * j <= n; j++) {
      if (j == 1)
        f[i] = i;
      else
        f[i * j] = min(f[i * j], max(f[j], i));
    }
  int ans = n, cnt = n;
  for (int i = 1; i <= n; i++)
    if (u[i])
      s[f[i]]++;
  for (int i = mn; i > 1; i--) {
    for (int j = 1; i * j <= n; j++)
      if (j == 1) {
        if (u[i])
          s[f[i]]--;
        f[i] = i;
        if (u[i])
          s[f[i]]++;
      } else {
        if (f[i * j] > max(f[j], i)) {
          if (u[i * j])
            s[f[i * j]]--;
          f[i * j] = max(f[j], i);
          if (u[i * j])
            s[f[i * j]]++;
        }
      }
    while (!s[cnt])
      cnt--;
    ans = min(ans, cnt - i);
  }
  if (mn == 1) {
    s[f[1]]--;
    while (cnt > 1 && !s[cnt])
      cnt--;
    ans = min(ans, cnt - 1);
  }
  cout << ans << '\n';
}

void clear() {
  memset(u + 1, 0, n);
  memset(s + 1, 0, n << 2);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
    clear();
  }
}