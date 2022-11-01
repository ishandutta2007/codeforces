#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <vector <int>> a(n, vector <int>(n));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        char c;
        cin >> c;
        a[i][j] = c - '0';
      }
    vector <vector <int>> b(n, vector <int>(n));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        char c;
        cin >> c;
        b[i][j] = c - '0';
      }
    for (int i = 0; i < n; i++)
      a[0][i] ^= 1;
    for (int i = 0; i < n; i++) {
      if (a[0][i] != b[0][i])
        for (int j = 0; j < n; j++)
          a[j][i] ^= 1;
    }
    for (int i = 1; i < n; i++) {
      bool flag = true;
      for (int j = 0; j < n; j++)
        if (a[i][j] != b[i][j])
          flag = false;
      if (!flag)
        for (int j = 0; j < n; j++)
          a[i][j] ^= 1;
    }
    bool flag = true;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (a[i][j] != b[i][j])
          flag = false;
    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}