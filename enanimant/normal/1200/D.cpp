// August 11, 2019
// https://codeforces.com/contest/1200/problem/D

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int N = 2005;


int n, k;
int a[N][N];
int psa[N][N];
int rows[N][N], cols[N][N];
int row_done[N], col_done[N];

int sum(int x1, int y1, int x2, int y2) {
  return psa[x2 + 1][y2 + 1] - psa[x2 + 1][y1] - psa[x1][y2 + 1] + psa[x1][y1];
}

bool allr(int r, int c) {
  return sum(r, c, r, c + k - 1) == sum(r, 0, r, n - 1);
}

bool allc(int r, int c) {
  return sum(r, c, r + k - 1, c) == sum(0, c, n - 1, c);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      a[i][j] = (c == 'B');
      psa[i + 1][j + 1] = psa[i + 1][j] + psa[i][j + 1] - psa[i][j] + a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    row_done[i] = true;
    col_done[i] = true;
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 1) {
        row_done[i] = false;
      }
      if (a[j][i] == 1) {
        col_done[i] = false;
      }
    }
  }
  for (int c = 0; c + k <= n; c++) {
    int cur = 0;
    for (int r = 0; r < k - 1; r++) {
      if (allr(r, c)) {
        cur++;
      }
    }
    int rd = 0;
    for (int i = k - 1; i < n; i++) {
      rd += row_done[i];
    }
    for (int r = k - 1; r < n; r++) {
      if (allr(r, c)) {
        cur++;
      }
      rd -= row_done[r];
      rows[r - k + 1][c] = cur + rd;
      if (allr(r - k + 1, c)) {
        cur--;
      }
      rd += row_done[r - k + 1];
    }
  }
  for (int r = 0; r + k <= n; r++) {
    int cur = 0;
    for (int i = 0; i < k - 1; i++) {
      if (allc(r, i)) {
        cur++;
      }
    }
    int cd = 0;
    for (int i = k - 1; i < n; i++) {
      cd += col_done[i];
    }
    for (int i = k - 1; i < n; i++) {
      if (allc(r, i)) {
        cur++;
      }
      cd -= col_done[i];
      cols[r][i - k + 1] = cur + cd;
      if (allc(r, i - k + 1)) {
        cur--;
      }
      cd += col_done[i - k + 1];
    }
  }
  int ans = 0;
  for (int i = 0; i + k <= n; i++) {
    for (int j = 0; j + k <= n; j++) {
      ans = max(ans, rows[i][j] + cols[i][j]);
    }
  }
  cout << ans << '\n';


  return 0;
}