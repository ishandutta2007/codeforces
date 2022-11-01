#include <iostream>
#include <vector>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

vvi mat;

int get(int x1, int y1, int x2, int y2) {
  x1--, y1--;
  return mat[x2][y2] - mat[x1][y2] - mat[x2][y1] + mat[x1][y1];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    mat.assign(n + 2, vi(n + 2, 0));
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (a[i] == a[j])
          mat[i + 1][j + 1] = 1;
    for (int i = 1; i <= n + 1; i++)
      for (int j = 1; j <= n + 1; j++)
        mat[i][j] += mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
    long long ans = 0;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (a[i] == a[j])
          ans += get(i + 2, j + 2, j, n + 1);
    cout << ans << '\n';
  }
  return 0;
}