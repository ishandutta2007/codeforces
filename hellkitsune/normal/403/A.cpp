#include <iostream>

using namespace std;

int e[24][24];
int b[2][12];

int main()
{
  int t;
  cin >> t;
  for (int test = 0; test < t; ++test) {
    int n, p;
    cin >> n >> p;
    p = n * (n - 1) / 2 - 2 * n - p;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        e[i][j] = 1;
    int st = 0;
    int nn = n + n % 2;
    while (p) {
      b[1][0] = nn - 1;
      for (int i = 1; i < nn / 2; ++i)
        b[1][i] = (st + i - 1) % (nn - 1);
      for (int i = 0; i < nn / 2; ++i)
        b[0][nn / 2 - i - 1] = (st + nn / 2 - 1 + i) % (nn - 1);
      for (int i = 0; i < nn / 2; ++i)
        if (!((n % 2) && ((b[0][i] == n) || (b[1][i] == n)))) {
          e[b[0][i]][b[1][i]] = 0;
          e[b[1][i]][b[0][i]] = 0;
          if (--p == 0)
            break;
        }
      ++st;
    }
    for (int i = 0; i < n - 1; ++i)
      for (int j = i + 1; j < n; ++j)
        if (e[i][j])
          cout << i + 1 << ' ' << j + 1 << endl;
  }
  return 0;
}