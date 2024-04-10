#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  if (a > 1 && b > 1 || (a == 1 && b == 1 && (n == 2 || n == 3))) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  if (a == 1 && b == 1) {
    vector <vector <int>> mat(n, vector <int>(n));
    for (int i = 0; i + 1 < n; i++)
      mat[i][i + 1] = mat[i + 1][i] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        cout << mat[i][j];
      cout << '\n';
    }
    return 0;
  }
  if (b == 1) {
    vector <vector <int>> mat(n, vector <int>(n));
    for (int i = a - 1; i < n; i++)
      for (int j = i + 1; j < n; j++)
        mat[i][j] = mat[j][i] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        cout << mat[i][j];
      cout << '\n';
    }
    return 0;
  }
  vector <vector <int>> mat(n, vector <int>(n, 1));
  for (int i = b - 1; i < n; i++)
    for (int j = i; j < n; j++)
      mat[i][j] = mat[j][i] = 0;
  for (int i = 0; i < n; i++)
    mat[i][i] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << mat[i][j];
    cout << '\n';
  }
  return 0;
}