#include <iostream>
#include <vector>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

vvi transp(vvi a) {
  int n = a.size();
  int m = a[0].size();
  vvi b(m, vi(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      b[j][i] = a[i][j];
  return b;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  bool flag = (n > m);
  vvi ans(n, vi(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      ans[i][j] = i * m + j + 1;
  if (n > m) {
    swap(n, m);
    ans = transp(ans);
  }
  if (n == 1 && m == 1) {
    cout << "YES\n" << 1;
    return 0;
  }
  if ((n == 1 && m == 2) || (n == 1 && m == 3) || (n == 2 && m == 2) || (n == 2 && m == 3)) {
    cout << "NO\n";
    return 0;
  }
  if (n == 3 && m == 3) {
    cout << "YES\n";
    cout << 1 << ' ' << 6 << ' ' << 8 << '\n';
    cout << 5 << ' ' << 7 << ' ' << 2 << '\n';
    cout << 9 << ' ' << 3 << ' ' << 4 << '\n';
    return 0;
  }
  if (n == 1) {
    ans.resize(0);
    cout << "YES\n";
    ans.push_back({});
    for (int i = m - (1 - m % 2); i >= 1; i -= 2)
      ans.back().push_back(i);
    for (int i = m - m % 2; i >= 1; i -= 2)
      ans.back().push_back(i);
    if (flag) {
      swap(n, m);
      ans = transp(ans);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        cout << ans[i][j] << ' ';
      cout << '\n';
    }
    return 0;
  }
  cout << "YES\n";
  for (int i = 0; i < n; i += 2)
    for (int it = 0; it < 2; it++)
      for (int j = 0; j + 1 < m; j++)
        swap(ans[i][j], ans[i][j + 1]);
  for (int i = 0; i + 1 < n; i++)
    for (int j = 0; j < m; j += 2)
      swap(ans[i][j], ans[i + 1][j]);
  if (flag) {
    swap(n, m);
    ans = transp(ans);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cout << ans[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}