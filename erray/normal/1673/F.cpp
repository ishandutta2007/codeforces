// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, K;
  cin >> N >> K;
  vector<int> row(32), col(32);
  int row_bits = 0;
  int col_bits = 0;
  for (int i = 0; i < 31; ++i) {
    int n = i ^ (i + 1);
    int p = __lg(n);
    row[i] |= 1 << (p * 2);
    col[i] |= 1 << (p * 2 + 1);
    row_bits |= 1 << (p * 2);
    col_bits |= 1 << (p * 2 + 1);
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N - 1; ++j) {
      cout << col[j] << ' ';
    }
    cout << '\n'; 
  }
  for (int i = 0; i < N - 1; ++i) {
    for (int j = 0; j < N; ++j) {
      cout << row[i] << ' ';
    }
    cout << '\n';
  }
  cout << endl;   
  for (int i = 0; i < 31; ++i) {
    row[i + 1] ^= row[i];
    col[i + 1] ^= col[i];
  }
  rotate(row.rbegin(), row.rbegin() + 1, row.rend());
  rotate(col.rbegin(), col.rbegin() + 1, col.rend());
  row[0] = col[0] = 0;
  debug(row, col);
  int x = 0, y = 0;
  while (K--) {
    int X;
    cin >> X;
    int new_x = -1, new_y = -1;
    for (int i = 0; i < N; ++i) {
      if ((row[i] ^ row[x]) == (X & row_bits)) {
        assert(new_x == -1);
        new_x = i; 
      }
      if ((col[i] ^ col[y]) == (X & col_bits)) {
        assert(new_y == -1);
        new_y = i;
      }
    } 
    assert(new_x != -1 && new_y != -1);

    swap(new_x, x);
    swap(new_y, y);
    cout << x + 1 << ' ' << y + 1 << endl;
  }
}