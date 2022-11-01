#include <iostream>
#include <vector>

using namespace std;

typedef vector <int> vi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vi a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int l = 1, r = n;
  while (l != r) {
    int m = (l + r + 1) / 2;
    vi x(n);
    for (int i = 0; i < n; i++) {
      if (a[i] >= m)
        x[i] = 1;
      else
        x[i] = -1;
    }
    vi dp(n);
    {
      int s = 0;
      for (int i = n - 1; i >= 0; i--) {
        s += x[i];
        if (s < 0)
          s = 0;
        dp[i] = s;
      }
    }
    vi pre(n);
    pre[0] = x[0];
    for (int i = 1; i < n; i++)
      pre[i] = pre[i - 1] + x[i];
    bool flag = false;
    for (int i = 0; i + k - 1 < n; i++) {
      int curs = pre[i + k - 1] - (i ? pre[i - 1] : 0);
      curs += (i + k != n ? dp[i + k] : 0);
      if (curs >= 1)
        flag = true;
    }
    if (!flag)
      r = m - 1;
    else
      l = m;
  }
  cout << l;
  return 0;
}