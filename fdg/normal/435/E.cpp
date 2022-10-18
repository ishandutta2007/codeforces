#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int f[1002][1002];

bool good(int a, int b) {
  return a == 0 || b == 0 || a == b;
}

int n, m;

bool goodRow(int r, int a, int b) {
  for (int i = 0; i < m; ++i) {
    if (!good(f[r][i], a)) return false;
    swap(a, b);
  }
  return true;
}

bool goodColumn(int c, int a, int b) {
  for (int i = 0; i < n; ++i) {
    if (!good(f[i][c], a)) return false;
    swap(a, b);
  }
  return true;
}

int main() {
  scanf("%d%d\n", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c;
      scanf("%c", &c);
      f[i][j] = c - '0';
    }
    scanf("\n");
  }
  for (int a1 = 1; a1 <= 4; ++a1) {
    for (int a2 = 1; a2 <= 4; ++a2) {
      if (a1 == a2) continue;
      for (int b1 = 1; b1 <= 4; ++b1) {
        if (a1 == b1 || a2 == b1) continue;
        int b2 = 10 - a1 - a2 - b1;
        bool ok = goodRow(0, a1, a2) && goodRow(1, b1, b2);
        for (int i = 2; i < n && ok; ++i) {
          if (i % 2 == 0) {
            if (!goodRow(i, a1, a2) && !goodRow(i, a2, a1)) {
              ok = false;
              break;
            }
          } else {
            if (!goodRow(i, b1, b2) && !goodRow(i, b2, b1)) {
              ok = false;
              break;
            }
          }
        }
        // cout << a1 << a2 << b1 << b2 << ok << endl;
        if (ok) {
          for (int i = 0; i < m; ++i) {
            f[0][i] = a1;
            swap(a1, a2);
            f[1][i] = b1;
            swap(b1, b2);
          }
          for (int i = 2; i < n; ++i) {
            if (i % 2 == 0) {
              if (goodRow(i, a1, a2)) {
                for (int j = 0; j < m; ++j) {
                  f[i][j] = a1;
                  swap(a1, a2);
                }
              } else {
                for (int j = 0; j < m; ++j) {
                  f[i][j] = a2;
                  swap(a1, a2);
                }
              }
            } else {
              if (goodRow(i, b1, b2)) {
                for (int j = 0; j < m; ++j) {
                  f[i][j] = b1;
                  swap(b1, b2);
                }
              } else {
                for (int j = 0; j < m; ++j) {
                  f[i][j] = b2;
                  swap(b1, b2);
                }
              }
            }
          }
          for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
              printf("%d", f[i][j]);
            printf("\n");
          }
          return 0;
        }
      }
    }
  }

  for (int a1 = 1; a1 <= 4; ++a1) {
    for (int a2 = 1; a2 <= 4; ++a2) {
      if (a1 == a2) continue;
      for (int b1 = 1; b1 <= 4; ++b1) {
        if (a1 == b1 || a2 == b1) continue;
        int b2 = 10 - a1 - a2 - b1;
        bool ok = goodColumn(0, a1, a2) && goodColumn(1, b1, b2);
        for (int i = 2; i < m && ok; ++i) {
          if (i % 2 == 0) {
            if (!goodColumn(i, a1, a2) && !goodColumn(i, a2, a1)) {
              ok = false;
              break;
            }
          } else {
            if (!goodColumn(i, b1, b2) && !goodColumn(i, b2, b1)) {
              ok = false;
              break;
            }
          }
        }
        // cout << a1 << a2 << b1 << b2 << ok << endl;
        if (ok) {
          for (int i = 0; i < n; ++i) {
            f[i][0] = a1;
            swap(a1, a2);
            f[i][1] = b1;
            swap(b1, b2);
          }
          for (int i = 2; i < m; ++i) {
            if (i % 2 == 0) {
              if (goodColumn(i, a1, a2)) {
                for (int j = 0; j < n; ++j) {
                  f[j][i] = a1;
                  swap(a1, a2);
                }
              } else {
                for (int j = 0; j < n; ++j) {
                  f[j][i] = a2;
                  swap(a1, a2);
                }
              }
            } else {
              if (goodColumn(i, b1, b2)) {
                for (int j = 0; j < n; ++j) {
                  f[j][i] = b1;
                  swap(b1, b2);
                }
              } else {
                for (int j = 0; j < n; ++j) {
                  f[j][i] = b2;
                  swap(b1, b2);
                }
              }
            }
          }
          for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
              printf("%d", f[i][j]);
            printf("\n");
          }
          return 0;
        }
      }
    }
  }
  puts("0");
  return 0;
}