#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef vector <ll> vl;
typedef vector <vl> vvl;
typedef vector <int> vi;
typedef vector <vi> vvi;

typedef long long ll;

mt19937 rnd(1);

vvi a;
vvl sum;

ll get(int x1, int x2, int y1, int y2) {
  x1--, y1--;
  ll res = sum[x2][y2];
  if (x1 >= 0)
    res -= sum[x1][y2];
  if (y1 >= 0)
    res -= sum[x2][y1];
  if (x1 >= 0 && y1 >= 0)
    res += sum[x1][y1];
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  a.resize(n, vi(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      a[i][j] = c - 'a';
    }
  vector <int> h(26);
  for (int i = 0; i < 26; i++)
    h[i] = rnd();
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      a[i][j] = h[a[i][j]];
  vvi ver(n, vi(m));
  for (int j = 0; j < m; j++) {
    ver[n - 1][j] = n;
    for (int i = n - 2; i >= 0; i--) {
      if (a[i][j] != a[i + 1][j])
        ver[i][j] = i + 1;
      else
        ver[i][j] = ver[i + 1][j];
    }
  }
  sum.resize(n, vl(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      sum[i][j] = a[i][j];
      if (i)
        sum[i][j] += sum[i - 1][j];
      if (j)
        sum[i][j] += sum[i][j - 1];
      if (i && j)
        sum[i][j] -= sum[i - 1][j - 1];
    }
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int i2 = ver[i][j];
      if (i2 == n)
        continue;
      int i3 = ver[i2][j];
      if (i3 == n)
        continue;
      if (a[i][j] == a[i2][j] || a[i3][j] == a[i2][j])
        continue;
      int i4 = ver[i3][j];
      ll hei = i2 - i;
      if (i3 - i2 != hei)
        continue;
      if (i4 - i3 < hei)
        continue;
      int L = j, R = m - 1;
      while (L != R) {
        int M = (L + R + 1) / 2;
        ll s = (M - j + 1) * hei;
        ll f1 = get(i, i2 - 1, j, M);
        ll f2 = get(i2, i3 - 1, j, M);
        ll f3 = get(i3, i3 + hei - 1, j, M);
        bool flag = true;
        if (f1 != s * a[i][j])
          flag = false;
        if (f2 != s * a[i2][j])
          flag = false;
        if (f3 != s * a[i3][j])
          flag = false;
        if (!flag)
          R = M - 1;
        else
          L = M;
      }
      ans += L - j + 1;
    }
  cout << ans;
  return 0;
}