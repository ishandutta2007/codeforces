#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    m++;
    vector <vector <char>> c(n, vector <char>(n));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cin >> c[i][j];
    bool flag = false;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) {
        if (flag)
          break;
        if (c[i][j] == c[j][i]) {
          flag = true;
          cout << "YES\n";
          for (int k = 0; k < m; k++) {
            if (k % 2)
              cout << i + 1 << ' ';
            else
              cout << j + 1 << ' ';
          }
          cout << '\n';
        }
      }
    if (flag)
      continue;
    if (m % 2 == 0) {
      cout << "YES\n";
      for (int k = 0; k < m; k++)
        cout << k % 2 + 1 << ' ';
      cout << '\n';
      continue;
    }
    if (n == 2) {
      cout << "NO\n";
      cout << '\n';
      continue;
    }
    vector <int> isha(n, -1);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (c[i][j] == 'a')
          isha[i] = j;
    for (int i = 0; i < n; i++) {
      if (flag)
        break;
      for (int j = 0; j < n; j++) {
        if (flag)
          break;
        if (c[i][j] != 'a' || isha[j] == -1)
          continue;
        flag = true;
        cout << "YES\n";
        int len = m / 2;
        for (int it = 0; it - 1 < len; it++) {
          if (it % 2 != len % 2)
            cout << i + 1 << ' ';
          else
            cout << j + 1 << ' ';
        }
        cout << isha[j] + 1 << ' ';
        for (int it = 0; it + 1 < len; it++) {
          if (it % 2 == 0)
            cout << j + 1 << ' ';
          else
            cout << isha[j] + 1 << ' ';
        }
        cout << '\n';
      }
    }
    vector <int> ishb(n, -1);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (c[i][j] == 'b')
          ishb[i] = j;
    for (int i = 0; i < n; i++) {
      if (flag)
        break;
      for (int j = 0; j < n; j++) {
        if (flag)
          break;
        if (c[i][j] != 'b' || ishb[j] == -1)
          continue;
        if (flag)
          break;
        flag = true;
        cout << "YES\n";
        int len = m / 2;
        for (int it = 0; it - 1 < len; it++) {
          if (it % 2 != len % 2)
            cout << i + 1 << ' ';
          else
            cout << j + 1 << ' ';
        }
        cout << ishb[j] + 1 << ' ';
        for (int it = 0; it + 1 < len; it++) {
          if (it % 2 == 0)
            cout << j + 1 << ' ';
          else
            cout << ishb[j] + 1 << ' ';
        }
        cout << '\n';
      }
    }
    if (!flag)
      cout << "NO\n";
  }
  return 0;
}