#include <bits/stdc++.h>

using namespace std;


const int N = 50;

int a[N][N];
int dp[2][N][N][N][N];

int ask(int r1, int c1, int r2, int c2) {
  cout << "? " << r1 + 1 << ' ' << c1 + 1 << ' ' << r2 + 1 << ' ' << c2 + 1 << endl;
  int r;
  cin >> r;
  return r;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

// #ifdef _DEBUG
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
//   freopen("debug_output.txt", "w", stderr);
// #endif


  int n;
  cin >> n;
  a[0][0] = 1;
  a[0][1] = 0;
  a[n - 1][n - 1] = 0;
  for (int j = 2; j < n; j++) {
    int r = ask(0, j - 2, 0, j);
    a[0][j] = a[0][j - 2] ^ r ^ 1;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      int r = ask(i - 1, j - 1, i, j);
      a[i][j] = a[i - 1][j - 1] ^ r ^ 1;
    }
    a[i][0] = a[i][2] ^ ask(i, 0, i, 2) ^ 1;
  }
  for (int a01 = 0; a01 < 2; a01++) {
    auto &d = dp[a01];
    for (int i = n - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        for (int ii = i; ii < n; ii++) {
          for (int jj = j; jj < n; jj++) {
            if ((i == ii && j == jj) || a[i][j] != a[ii][jj]) {
              continue;
            }
            int res = 0;
            if (ii + jj == i + j + 1) {
              res = 1;
            } else {
              res |= (d[i + 1][j][ii - 1][jj]);
              res |= (d[i + 1][j][ii][jj - 1]);
              res |= (d[i][j + 1][ii - 1][jj]);
              res |= (d[i][j + 1][ii][jj - 1]);
            }
            d[i][j][ii][jj] = res;
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if ((i + j) % 2 == 1) {
          a[i][j] ^= 1;
        }
      }
    }
  }
  int r1 = -1, c1 = -1, r2 = -1, c2 = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int ii = i; ii < n; ii++) {
        for (int jj = j; jj < n; jj++) {
          if (ii + jj < i + j + 2) {
            continue;
          }
          if (dp[0][i][j][ii][jj] ^ dp[1][i][j][ii][jj]) {
            r1 = i;
            c1 = j;
            r2 = ii;
            c2 = jj;
          }
        }
      }
    }
  }
  if (ask(r1, c1, r2, c2) == dp[1][r1][c1][r2][c2]) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if ((i + j) % 2 == 1) {
          a[i][j] ^= 1;
        }
      }
    }
  }
  cout << "!\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j];
    }
    cout << '\n';
  }


  return 0;
}